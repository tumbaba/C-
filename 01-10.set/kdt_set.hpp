#include "kdt_set.h"
namespace kdt
{
	template<typename _Ty>
	inline _CONSTEXPR20 set<_Ty>::iterator set<_Ty>::insert(const _Ty& InValue)
	{
		return iterator();
	}
	template<typename _Ty>
	inline _CONSTEXPR20 set<_Ty>::iterator set<_Ty>::find(const _Ty& InValue)
	{
		return iterator();
	}
	template<typename _Ty>
	inline _CONSTEXPR20 set<_Ty>::iterator set<_Ty>::erase(const iterator& It)
	{
		return iterator();
	}
	template<typename _Ty>
	inline _CONSTEXPR20 set<_Ty>::iterator kdt::set<_Ty>::begin()
	{
		return iterator();
	}
	template<typename _Ty>
	inline _CONSTEXPR20 set<_Ty>::iterator set<_Ty>::end()
	{
		return iterator();
	}
}