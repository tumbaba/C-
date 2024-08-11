#pragma once

namespace kdt
{
	template<class _Ty>
	template<class ..._Valty>
	inline _CONSTEXPR20 _Ty& vector<_Ty>::_Emplace_one_at_back(_Valty && ..._Val)
	{
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
	}

	template<class _Ty>
	template<class... _Valty>
	inline _CONSTEXPR20 decltype(auto) kdt::vector<_Ty>::emplace_back(_Valty && ..._Val)
	{
		// std::forward: LValue로 들어온 인자는 LValue로, RValue로 들어온 인자는 RValue
		_Ty& _Result = _Emplace_one_at_back(std::forward<_Valty>(_Val)...);
		return _Result;
	}

	template<class _Ty>
	inline _CONSTEXPR20 void vector<_Ty>::push_back(_Ty&& _Val)
	{
		_Emplace_one_at_back(std::move(_Val));
	}

	template<class _Ty>
	inline _CONSTEXPR20 void vector<_Ty>::reserve(const size_t InSize)
	{
		if (Size > InSize)
		{
			return;
		}

		reserve_impl(InSize);
	}

	template<class _Ty>
	inline _CONSTEXPR20 void vector<_Ty>::resize(const size_t InSize)
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
			emplace_back();
		}
	}

	template<class _Ty>
	inline _CONSTEXPR20 void vector<_Ty>::clear() noexcept
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

	template<class _Ty>
	inline void vector<_Ty>::reserve_impl(const size_t InSize)
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

	template<class _Ty>
	inline _CONSTEXPR20 bool vector<_Ty>::erase(const iterator _Where)
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
				return true;
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

	template<class _Ty>
	inline _CONSTEXPR20 void vector<_Ty>::push_back(const _Ty& _Val)
	{
		_Emplace_one_at_back(_Val);
	}
}