#pragma once
namespace kdt
{

	template<typename _Ty>
	class _Set_iterator
	{

	};

	template<typename _Ty1, typename _Ty2>
	struct FPair
	{
		_Ty1 first;
		_Ty2 second;
	};

	enum class ENodeType
	{
		Parent,
		Left, // Left Child
		Right, // Right Child
		End,
	};

	// template<typename _Ty1, typename _Ty2> // 만약에 map이였다면
	template<typename _Ty>
	// BST: Binary Search Tree(이진 탐색 트리)
	struct FBSTNode
	{
		//FPair Pair;
		_Ty Value {};

		FBSTNode* Nodes[(int)ENodeType::End] = {};
		
		FBSTNode() : Value{}, Nodes{} {}
		FBSTNode(const _Ty& InValue, FBSTNode* InParent,
			FBSTNode* InLeft, FBSTNode* InRight) : Value(InValue),
			Nodes{ InParent, InLeft, InRight } {}
	};

	// 일단 int만 가정해서 처리
	template<typename _Ty>
	class set
	{
	public:
		using iterator = _Set_iterator<_Ty>;

		_NODISCARD _CONSTEXPR20 iterator insert(const _Ty& InValue);
		_NODISCARD _CONSTEXPR20 iterator find(const _Ty& InValue);
		_NODISCARD _CONSTEXPR20 iterator erase(const iterator& It);

		_NODISCARD _CONSTEXPR20 iterator begin();
		_NODISCARD _CONSTEXPR20 iterator end();

	private:
		FBSTNode<_Ty>* Root = nullptr;
		size_t Count = 0;
	};
}

#include "kdt_set.hpp"