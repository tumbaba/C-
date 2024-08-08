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
		_CONSTEXPR20 _Ty& _Emplace_one_at_back(_Valty&&... _Val) 
		{
			if (IsFull())
			{
				// 1.5배로 늘리고 싶은 경우
				//size_t NewSize = round(Size * 1.5); // round 함수는 반올림(반올림 안하면 1 * 1.5 = 1)
				// 또는 Size * 1.5 + 0.5
				reserve_impl(Size * 2);
			}
			const size_t OriginSize = Size;
			new(Array + Size)_Ty(std::forward<_Valty>(_Val)...);
			++Size;

			return *(Array + OriginSize);
		}

	public:
		using iterator = _Vector_iterator<_Ty>;

		_NODISCARD _CONSTEXPR20 iterator begin() noexcept 
		{
			return iterator(Array);
		}

		_NODISCARD _CONSTEXPR20 iterator end() noexcept 
		{
			return iterator(Array + Size);
		}

		template <class... _Valty>
		_CONSTEXPR20 decltype(auto) emplace_back(_Valty&&... _Val) 
		{
			_Ty& _Result = _Emplace_one_at_back(std::forward<_Valty>(_Val)...);
			return _Result;
		}

		_CONSTEXPR20 void push_back(const _Ty& _Val)
		{
			_Emplace_one_at_back(_Val);
		}
		_CONSTEXPR20 void push_back(_Ty&& _Val)
		{
			_Emplace_one_at_back(std::move(_Val));
		}

		_CONSTEXPR20 void reserve(const size_t InSize)
		{
			if (InSize == 0)
			{
				clear();
				return;
			}

			if (Size > InSize)
			{
				return;
			}

			reserve_impl(InSize);
		}

		_CONSTEXPR20 void resize(const size_t InSize)
		{
			if (InSize == 0)
			{
				clear();
				return;
			}

			const size_t OriginSize = Size;
			reserve_impl(InSize);
			for (size_t i = OriginSize; i < InSize; ++i)
			{
				push_back({});
			}
		}

		_CONSTEXPR20 bool erase(const iterator _Where)
		{
			if (empty())
			{
				return false;
			}

			_Ty* Pointer = _Where.Pointer;
			// 지정된 범위에 있고
			if (Array <= Pointer && Pointer <= Array + Size - 1)
			{
#ifdef _DEBUG
				// Size로 나눴을때 나머지가 0인 경우
				const size_t Offset = (unsigned char*)Pointer - (unsigned char*)Array;
				const size_t Test = Offset % sizeof(_Ty);
				if (Test != 0)
				{
					_ASSERT(false);
					return false;
				}
#endif
				--Size;
				if (Size == 0)
				{
					clear();
					return false;
				}

				const size_t EraseIndex = Pointer - Array;
				for (size_t i = EraseIndex; i < Size; ++i)
				{
					Array[i] = std::move(Array[i + 1]);
				}
				// 마지막 원소는 소멸자 호출
				Array[Size].~_Ty();
				return true;
			}

			_ASSERT(false);
			return false;
		}

		_CONSTEXPR20 void clear() noexcept
		{
			if (Array == nullptr) { return; }

			for (size_t i = 0; i < Size; ++i)
			{
				Array[i].~_Ty();
			}
			free(Array);
			Array = nullptr;

			Size = 0;
			Capacity = 0;
		}

		_NODISCARD _CONSTEXPR20 bool empty() const noexcept
		{
			return Size == 0;
		}

		_NODISCARD _CONSTEXPR20 size_t size() const noexcept { return Size; }
		_NODISCARD _CONSTEXPR20 size_t capacity() const noexcept { return Capacity; }

		_NODISCARD _CONSTEXPR20 _Ty& operator[](const size_t _Pos) noexcept
		{
			return Array[_Pos];
		}

	public:
		vector() = default;
		~vector()
		{
			if (Capacity != 0)
			{
				clear();
			}
		}

	protected:
		// 내부 호출 전용, InSize가 0인 경우 1로 처리
		// clear 이후 push_back 대응
		void reserve_impl(size_t InSize)
		{
			const static size_t MinSize = 1;
			// end 위치가 될 공간을 위해 + 1 을 해줬다
			const size_t NewCapacity = std::max(InSize, MinSize);
			const size_t NewAllocSize = sizeof(_Ty) * (NewCapacity + 1);
			_Ty* NewArray = reinterpret_cast<_Ty*>(malloc(NewAllocSize));

			// 배열이 비어 있지 않은 경우
			{
				if (!empty())
				{
					// Array에 있던 데이터를 NewArray로 복사
					const size_t OriginSize = Size;
					// 원래 10
					// 5개로 줄어드는 경우
					// 10 > 5 ? NewCapacity(5) : Size(10);
					// 5 > 10 ? NewCapacity(10) : Size(5)
					Size = Size > NewCapacity ? NewCapacity : Size;
					for (size_t i = 0; i < Size; ++i)
					{
						new(NewArray + i)_Ty(std::move(Array[i]));
					}
					for (size_t i = 0; i < OriginSize; ++i)
					{
						Array[i].~_Ty();
					}
				}

				// 복사 이후에 기존 Array는 free
				if (Array)
				{
					free(Array);
					Array = nullptr;
				}
			}

			// 신규 할당된 NewArray의 주소를 Array에 덮어쓴다
			Array = NewArray;
			Capacity = NewCapacity;
		}

	protected:
		bool IsFull() const
		{
			return Size == Capacity;
		}

	protected:
		_Ty* Array = nullptr;
		size_t Size = 0;			// 실제로 할당된 원소의 갯수
		size_t Capacity = 0;		// 할당 가능한 총 원소의 갯수
	};
}