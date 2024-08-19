#pragma once
#include <iostream>
#include <chrono>
#include <format>
#include <vector>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>

class FClass
{
public:
	FClass()
	{
		//std::cout << __FUNCTION__ << std::endl;
	}
	FClass(int InValue)
		: Data2(InValue)
	{

	}
	~FClass()
	{
		//std::cout << __FUNCTION__ << std::endl;
	}

private:
	char Data[1024] = {};
	int Data2 = {};
};

// 고정 사이즈 Memory pool
class FMemoryPool
{
public:
	FMemoryPool(const size_t InChunkSize, const size_t InChunkCount) noexcept
		: ChunkSize(InChunkSize)
		, ChunkCount(InChunkCount)
	{
		const size_t Align = 8;
		// https://stackoverflow.com/questions/45213511/formula-for-memory-alignment
		// InChunkSize: 4
		// Align: 8
		// 
		// 4 + (8 - 1) = 11
		// 11 -> 1011(2진)

		// 1011
		// 1000 (8 - 1 -> 7(0111) bit not 1000)
		// ----- AND
		// 1000 (8)
		//const size_t AlignedChunkSize = ((InChunkSize + (Align - 1)) & ~(Align - 1));
		//const size_t TotalMemorySize = AlignedChunkSize * ChunkCount;
		//StartAddress = ::_aligned_malloc(TotalMemorySize, Align);

		const size_t TotalMemorySize = InChunkSize * ChunkCount;
		StartAddress = ::malloc(TotalMemorySize);

		/*std::cout << std::format("[MemoryPool] ChunkSize: {}, ChunkCount:{}, TotalMemorySize: {}\n", 
			ChunkSize, ChunkCount, TotalMemorySize);*/

		ActiveMemoryBlock.reserve(InChunkCount);
		for (size_t i = 0; i < ChunkCount; ++i)
		{
			//uint8_t* Memory = (uint8_t*)StartAddress + i * AlignedChunkSize;
			uint8_t* Memory = (uint8_t*)StartAddress + i * InChunkSize;
			ActiveMemoryBlock.emplace_back(Memory);
		}
	}
	FMemoryPool(const FMemoryPool&) = delete;
	FMemoryPool& operator=(const FMemoryPool&) = delete;

	~FMemoryPool()
	{
		_ASSERT(StartAddress);
		free(StartAddress);
		//::_aligned_free(StartAddress);
	}

	void* malloc()
	{
		if (ActiveMemoryBlock.empty())
		{
			// 남은 Memory가 pool에 없다
			_ASSERT(false);
			return nullptr;
		}

		void* Memory = ActiveMemoryBlock.back();
		ActiveMemoryBlock.pop_back();
		return Memory;
	}
	
	void free(void* InMemory)
	{
		ActiveMemoryBlock.emplace_back(InMemory);
	}

private:
	const size_t ChunkSize;
	const size_t ChunkCount;
	void* StartAddress = nullptr;
	std::vector<void*> ActiveMemoryBlock;
};

template<class T>
class FObjectPool : public FMemoryPool
{
public:
	FObjectPool(const size_t InMaxObjectCount)
		: FMemoryPool(sizeof(T), InMaxObjectCount) {}

	template<class... Args>
	T* construct(Args&&...InArgs)
	{
		T* const ret = reinterpret_cast<T*>(malloc());
		if (ret == nullptr)
			return ret;

		try 
		{
			new (ret)T(std::forward<Args>(InArgs)...);
		}
		catch (...) { (free)(ret); throw; }
		return ret;
	}

	template<class... Args>
	std::shared_ptr<T> construct_shared(Args&&...InArgs)
	{
		T* ret = construct(std::forward<Args>(InArgs)...);

		return std::shared_ptr<T>{ret,
			[this](T* InPointer) 
			{
				this->destroy(InPointer);
			}};
	}

	void destroy(T* const chunk)
	{
		chunk->~T();
		(free)(chunk);
	}
};

namespace boost
{
	template <typename T, typename UserAllocator = default_user_allocator_new_delete>
	class object_pool_custom : public object_pool<T, UserAllocator>
	{
	public:
		typedef T element_type; //!< ElementType
		typedef UserAllocator user_allocator; //!<
		typedef typename pool<UserAllocator>::size_type size_type; //!<   pool<UserAllocator>::size_type
		typedef typename pool<UserAllocator>::difference_type difference_type; //!< pool<UserAllocator>::difference_type
		
		explicit object_pool_custom(const size_type arg_next_size = 32, const size_type arg_max_size = 0)
			: object_pool<T, UserAllocator>(arg_next_size, arg_max_size)
		{
		}

		// Returns 0 if out-of-memory.
		element_type* malloc BOOST_PREVENT_MACRO_SUBSTITUTION()
		{
			return static_cast<element_type*>(store().malloc());
		}
		void free BOOST_PREVENT_MACRO_SUBSTITUTION(element_type* const chunk)
		{
			store().free(chunk);
		}
		template<class... Args>
		element_type* construct(Args&&...InArgs)
		{ 
			element_type* const ret = (malloc)();
			if (ret == 0)
				return ret;
			try { new (ret) element_type(std::forward<Args>(InArgs)...); }
			catch (...) { (free)(ret); throw; }
			return ret;
		}
		void destroy(element_type* const chunk)
		{ 
			chunk->~T();
			(free)(chunk);
		}

		template<class... Args>
		std::shared_ptr<T> construct_shared(Args&&...InArgs)
		{
			T* ret = construct(std::forward<Args>(InArgs)...);

			return std::shared_ptr<T>{ret,
				[this](T* InPointer)
				{
					this->destroy(InPointer);
				}};
		}

	protected:
		//! \return The underlying boost:: \ref pool storage used by *this.
		pool<UserAllocator>& store()
		{
			return *this;
		}
		//! \return The underlying boost:: \ref pool storage used by *this.
		const pool<UserAllocator>& store() const
		{
			return *this;
		}

	};
}


const size_t MaxCount = 1000000;
template <class _Ty>
class FAllocator 
{
public:
	static inline std::shared_ptr<boost::pool<>> _MemoryPool;
	static_assert(!std::is_const_v<_Ty>, "The C++ Standard forbids containers of const elements "
		"because FAllocator<const T> is ill-formed.");
	static_assert(!std::is_function_v<_Ty>, "The C++ Standard forbids allocators for function elements "
		"because of [FAllocator.requirements].");
	static_assert(!std::is_reference_v<_Ty>, "The C++ Standard forbids allocators for reference elements "
		"because of [FAllocator.requirements].");

	using _From_primary = FAllocator;

	using value_type = _Ty;

	using size_type = size_t;
	using difference_type = ptrdiff_t;

	constexpr FAllocator() noexcept 
	{
		/*if (_MemoryPool == nullptr)
		{
			_MemoryPool = std::make_shared<boost::pool<>>(sizeof(_Ty), MaxCount);
		}*/
	}

	constexpr FAllocator(const FAllocator&) noexcept = default;
	template <class _Other>
	constexpr FAllocator(const FAllocator<_Other>&) noexcept 
	{
		if (_MemoryPool == nullptr)
		{
			_MemoryPool = std::make_shared<boost::pool<>>(sizeof(_Ty), MaxCount);
		}
	}
	_CONSTEXPR20 ~FAllocator() = default;
	_CONSTEXPR20 FAllocator& operator=(const FAllocator&) = default;

	_CONSTEXPR20 void deallocate(_Ty* const _Ptr, const size_t _Count) 
	{
		_MemoryPool->free(_Ptr);
		//std::_Deallocate<std::_New_alignof<_Ty>>(_Ptr, sizeof(_Ty) * _Count);
	}

	_NODISCARD_RAW_PTR_ALLOC _CONSTEXPR20 __declspec(allocator) _Ty* allocate(_CRT_GUARDOVERFLOW const size_t _Count) 
	{
		//return static_cast<_Ty*>(_STD _Allocate<std::_New_alignof<_Ty>>(std::_Get_size_of_n<sizeof(_Ty)>(_Count)));

		return static_cast<_Ty*>(_MemoryPool->malloc());
	}
};