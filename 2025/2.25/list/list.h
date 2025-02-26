#pragma once

#include <iostream>
using namespace std;


namespace xiong
{
	//////////////////////////////////////////////////
	// 定义 List 节点
	template <class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _next(nullptr)
			, _prev(nullptr)
			, _val(val)
	{}
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _val;
};
	//////////////////////////////////////////////////
	// List 正向迭代器
	template <class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;

	public:
		typedef Ref Ref;
		typedef Ptr Ptr;
	public:
		//////////////////////////////////////////////
		// 构造
		ListIterator(Node* node = nullptr)
			:_node(node)
		{
		}

		//////////////////////////////////////////////
		// 指针操作
		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		//////////////////////////////////////////////
		// 迭代器移动操作
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator++(int)
		{
			Self temp(*this);
			_node = _node->_next;
			return temp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self& operator--(int)
		{
			Self temp(*this);
			_node = _node->_prev;
			return temp;
		}

		//////////////////////////////////////////////
		// 迭代器比较操作
		bool operator==(const Self& l)const
		{
			return _node == l._node;
		}

		bool operator!=(const Self& l)const
		{
			return _node != l._node;
		}

		Node* _node;
	};

	//////////////////////////////////////////////////
	// List 反向迭代器
	template <class Iterator>
	class ReverseIterator
	{
	public:
		typedef typename Iterator::Ref Ref;
		typedef typename Iterator::Ptr Ptr;
		typrdef ReverseIterator<Iterator> Self;
	public:
		//////////////////////////////////////////////
		// 构造
		ReverseIterator(Iterator it)
			:_it(it)
		{}

		//////////////////////////////////////////////
		// 指针操作
		Ref operator*()
		{
			return 
		}





















































	};





































	}








