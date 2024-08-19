namespace kdt
{
	template<typename _Ty>
	inline kdt::set<_Ty>::set(const set& InOther)
	{
		std::cout << std::endl << "Preorder_Tree_Walk Copy start\n";
		Preorder_Tree_Walk(InOther.Root,
			[this](Node* x)
			{
				std::cout << x->Key << " ";
				insert(x->Key);
			}
		);
		std::cout << std::endl << "Preorder_Tree_Walk Copy end\n";
	}
	template<typename _Ty>
	kdt::set<_Ty>::set(set&& InOther) noexcept
	{
		Root = InOther.Root;
		InOther.Root = nullptr;
	}
	template<typename _Ty>
	inline kdt::set<_Ty>::~set()
	{
		std::cout << std::endl << "Postorder_Tree_Walk Delete start\n";
		Postorder_Tree_Walk(Root, 
			[](Node* x)
			{
				std::cout << x->Key << " ";
				delete x;
			}
		);
		std::cout << std::endl << "Postorder_Tree_Walk Delete end\n";
	}

	template<typename _Ty>
	inline set<_Ty>::iterator set<_Ty>::insert(const _Ty& InKey)
	{
		Node* NewNode = new Node(InKey, nullptr, nullptr, nullptr);
		BST_Insert(NewNode);
		return iterator(this, NewNode);
	}
	template<typename _Ty>
	inline set<_Ty>::iterator set<_Ty>::find(const _Ty& InKey)
	{
		Node* FindNode = Iterative_Tree_Search(Root, InKey);

		return iterator(this, FindNode);
	}
	template<typename _Ty>
	inline set<_Ty>::iterator set<_Ty>::erase(const iterator& It)
	{
		Node* SuccessorNode = BST_Delete(It.Node);
		return iterator(this, SuccessorNode);
	}
	template<typename _Ty>
	inline set<_Ty>::iterator kdt::set<_Ty>::begin()
	{
		Node* Temp = Root;
		while (Temp->Left)
		{
			Temp = Temp->Left;
		}
		return iterator(this, Temp);
	}
	template<typename _Ty>
	inline set<_Ty>::iterator set<_Ty>::end()
	{
		return iterator(this, nullptr);
	}
	template<typename _Ty>
	inline void set<_Ty>::print_inorder()
	{
		std::cout << std::endl << "Inorder_Tree_Walk Print start\n";
		Inorder_Tree_Walk(Root, 
			[](Node* x)
			{
				std::cout << x->Key << " ";
			}
		);
		std::cout << std::endl << "Inorder_Tree_Walk Print end\n";
	}
	template<typename _Ty>
	inline void kdt::set<_Ty>::BST_Insert(Node* z)
	{
		Node* y = nullptr;
		Node* x = Root;

		while (x != nullptr)
		{
			y = x;
			if (z->Key < x->Key)
			{
				x = x->Left;
			}
			else
			{
				x = x->Right;
			}
		}

		z->Parent = y;
		if (y == nullptr)
		{
			// 처음 들어온 원소를 Root로 만들어 준다
			Root = z;
		}
		else if (z->Key < y->Key)
		{
			y->Left = z;
		}
		else if (z->Key > y->Key)
		{
			y->Right = z;
		}
		else
		{
			// 동일한 Key를 넣은 경우
			// 우리는 허용하지 않는다
			_ASSERT(false);
		}
	}

	template<typename _Ty>
	inline set<_Ty>::Node* set<_Ty>::Iterative_Tree_Search(Node* x, const _Ty& key)
	{
		while (x != nullptr && key != x->Key)
		{
			if (key < x->Key)
			{
				x = x->Left;
			}
			else
			{
				x = x->Right;
			}
		}

		return x;
	}

	template<typename _Ty>
	inline set<_Ty>::Node* set<_Ty>::BST_Delete(Node* D)
	{
		Node* E = BST_Successor(D);
		if (D->Left == nullptr)
		{
			Shift_Nodes(D, D->Right);
		}
		else if (D->Right == nullptr)
		{
			Shift_Nodes(D, D->Left);
		}
		else
		{
			if (E->Parent != D)
			{
				Shift_Nodes(E, E->Right);
				E->Right = D->Right;
				E->Right->Parent = E;
			}
			Shift_Nodes(D, E);
			E->Left = D->Left;
			E->Left->Parent = E;
		}
		delete D;
		return E;

		// BST_Predecessor version
		/*Node* E = BST_Predecessor(D);
		if (D->Left == nullptr)
		{
			Shift_Nodes(D, D->Right);
		}
		else if (D->Right == nullptr)
		{
			Shift_Nodes(D, D->Left);
		}
		else
		{
			if (E->Parent != D)
			{
				Shift_Nodes(E, E->Left);
				E->Left = D->Left;
				E->Left->Parent = E;
			}
			Shift_Nodes(D, E);
			E->Right = D->Right;
			E->Right->Parent = E;
		}
		delete D;
		return E;*/
	}

	template<typename _Ty>
	inline void set<_Ty>::Shift_Nodes(Node* u, Node* v)
	{
		if (u->Parent == nullptr)
		{
			Root = v;
		}
		else if (u == u->Parent->Left)
		{
			u->Parent->Left = v;
		}
		else
		{
			u->Parent->Right = v;
		}
		if (v != nullptr)
		{
			v->Parent = u->Parent;
		}
	}

	template<typename _Ty>
	inline set<_Ty>::Node* set<_Ty>::BST_Successor(Node* x)
	{
		if (x->Right != nullptr)
		{
			return BST_Minimum(x->Right);
		}
		
		Node* y = x->Parent;
		while (y != nullptr && x == y->Right)
		{
			x = y;
			y = y->Parent;
		}

		return y;
	}

	template<typename _Ty>
	inline set<_Ty>::Node* set<_Ty>::BST_Minimum(Node* x)
	{
		while (x->Left != nullptr)
		{
			x = x->Left;
		}
		return x;
	}

	template<typename _Ty>
	inline set<_Ty>::Node* set<_Ty>::BST_Predecessor(Node* x)
	{
		if (x->Left != nullptr)
		{
			return BST_Maximum(x->Left);
		}

		Node* y = x->Parent;
		while (y != nullptr && x == y->Left)
		{
			x = y;
			y = y->Parent;
		}

		return y;
	}

	template<typename _Ty>
	inline set<_Ty>::Node* set<_Ty>::BST_Maximum(Node* x)
	{
		while (x->Right != nullptr)
		{
			x = x->Right;
		}
		return x;
	}

	// -------------------------------------Traversal--------------------------------------
	// 순서대로 출력할 때 사용
	template<typename _Ty>
	inline void set<_Ty>::Inorder_Tree_Walk(Node* x, std::function<void(Node*)> Function)
	{
		if (x == nullptr) { return; }

		Inorder_Tree_Walk(x->Left, Function);
		Function(x);
		Inorder_Tree_Walk(x->Right, Function);
	}

	// Tree를 복제할 때 사용 (부모-> 자식으로 향함)
	template<typename _Ty>
	inline void set<_Ty>::Preorder_Tree_Walk(Node* x, std::function<void(Node*)> Function)
	{
		if (x == nullptr) { return; }

		Function(x);
		Preorder_Tree_Walk(x->Left, Function);
		Preorder_Tree_Walk(x->Right, Function);
	}

	// Tree를 delete 할 때 사용 (자식 -> 부모로 향함)
	template<typename _Ty>
	inline void set<_Ty>::Postorder_Tree_Walk(Node* x, std::function<void(Node*)> Function)
	{
		if (x == nullptr) { return; }

		Postorder_Tree_Walk(x->Left, Function);
		Postorder_Tree_Walk(x->Right, Function);
		Function(x);
	}
}