#pragma once
// https://learn.microsoft.com/ko-kr/visualstudio/debugger/create-custom-views-of-native-objects?view=vs-2022

namespace kdt
{
	int Test()
	{
		return 5;
	}

	template<class _Ty>
	class _Vector_iterator
	{
		template<class _Ty>
		friend class vector;
	public:
		_Vector_iterator() = default;
		_Vector_iterator(_Ty* InPointer) : Pointer(InPointer) {}
		_Vector_iterator(const _Vector_iterator&) = default;
		_Vector_iterator& operator=(const _Vector_iterator&) = default;

		bool operator==(const _Vector_iterator& InIter)
		{
			return Pointer == InIter.Pointer;
		}

		bool operator!=(const _Vector_iterator& InIter)
		{
			return Pointer != InIter.Pointer;
		}

		// 선행 증가
		_Vector_iterator& operator++()
		{
			if (Pointer)
			{
				//Pointer = Pointer + 1;
				++Pointer;
			}
			return *this;
		}

		// 후행 증가
		_Vector_iterator operator++(int)
		{
			_Vector_iterator Temp = *this;
			_Vector_iterator::operator++();
			return Temp;
		}

		_Vector_iterator& operator--()
		{
			if (Pointer)
			{
				//Pointer = Pointer - 1;
				--Pointer;
			}
			return *this;
		}
		_Vector_iterator operator--(int)
		{
			_Vector_iterator Temp = *this;
			_Vector_iterator::operator--();
			return Temp;
		}
		_Ty& operator*() const
		{
			return *Pointer;
		}
		_Ty* operator->() const
		{
			return Pointer;
		}
	private:
		_Ty* Pointer = nullptr;
	};

	//template<typename T>
	template<class _Ty>
	class vector
	{
	private:
		template <class... _Valty>
		_CONSTEXPR20 _Ty& _Emplace_one_at_back(_Valty&&... _Val);

	public:
		using iterator = _Vector_iterator<_Ty>;

		_NODISCARD _CONSTEXPR20 iterator begin() noexcept { return iterator(Array); }
		_NODISCARD _CONSTEXPR20 iterator end() noexcept  { return iterator(Array + Size); }

		template <class... _Valty>
		_CONSTEXPR20 decltype(auto) emplace_back(_Valty&&... _Val);
		_CONSTEXPR20 void push_back(const _Ty& _Val);
		_CONSTEXPR20 void push_back(_Ty&& _Val);

		_CONSTEXPR20 void reserve(const size_t InSize);
		_CONSTEXPR20 void resize(const size_t InSize);
		_CONSTEXPR20 bool erase(const iterator _Where);
		_CONSTEXPR20 void clear() noexcept;

		_NODISCARD _CONSTEXPR20 bool empty() const noexcept { return Size == 0; }
		_NODISCARD _CONSTEXPR20 size_t size() const noexcept { return Size; }
		_NODISCARD _CONSTEXPR20 size_t capacity() const noexcept { return Capacity; }
		_NODISCARD _CONSTEXPR20 _Ty& operator[](const size_t _Pos) noexcept { return Array[_Pos]; }

	public:
		vector() = default;
		~vector() { if (Capacity != 0) { clear(); } }

	protected:
		// 내부 호출 전용, InSize가 0인 경우 1로 처리
		// clear 이후 push_back 대응
		void reserve_impl(const size_t InSize);

	protected:
		bool IsFull() const { return Size == Capacity; }

	protected:
		_Ty* Array = nullptr;
		size_t Size = 0;			// 실제로 할당된 원소의 갯수
		size_t Capacity = 0;		// 할당 가능한 총 원소의 갯수
	};
}

#include "Vector.hpp"