#pragma once
namespace kdt
{
	int Test()
	{
		return 5;
	}

	//template<typename T>
	template<class _Ty>
	class vector
	{
	public:
		_CONSTEXPR20 void push_back(const _Ty& _Val)
		{
			if (IsFull())
			{
				// 1.5배로 늘리고 싶은 경우
				//size_t NewSize = round(Size * 1.5); // round 함수는 반올림(반올림 안하면 1 * 1.5 = 1)
				// 또는 Size * 1.5 + 0.5
				reserve(Size * 2);
			}

			new(Array + Size)_Ty(_Val);
			++Size;
		}
		_CONSTEXPR20 void push_back(_Ty&& _Val)
		{
			if (IsFull())
			{
				// 1.5배로 늘리고 싶은 경우
				//size_t NewSize = round(Size * 1.5); // round 함수는 반올림(반올림 안하면 1 * 1.5 = 1)
				// 또는 Size * 1.5 + 0.5
				reserve(Size * 2);
			}

			new(Array + Size)_Ty(std::move(_Val));
			++Size;
		}

		_CONSTEXPR20 void reserve(const size_t InSize)
		{
			if (InSize == 0)
			{
				return;
			}

			// end 위치가 될 공간을 위해 + 1 을 해줬다
			const size_t NewCapacity = InSize;
			const size_t NewAllocSize = sizeof(_Ty) * (NewCapacity + 1);
			_Ty* NewArray = reinterpret_cast<_Ty*>(malloc(NewAllocSize));

			// 배열이 비어 있지 않은 경우
			{
				if (!empty())
				{
					// @TODO: 나중에 Array에 있던 데이터를 NewArray로 복사 해야함
				}

				// @TODO: 복사 이후에 기존 Array는 free 해야함
			}

			// 신규 할당된 NewArray의 주소를 Array에 덮어쓴다
			Array = NewArray;
			Capacity = NewCapacity;
		}

		_CONSTEXPR20 void resize(const size_t InSize)
		{

		}

		_CONSTEXPR20 void clear() noexcept
		{

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
			if (!empty())
			{
				clear();
			}
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