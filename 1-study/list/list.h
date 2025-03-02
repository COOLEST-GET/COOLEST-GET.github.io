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

		Self operator++(int)
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

		Self operator--(int)
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
	class ReverseListIterator
	{
	public:
		typedef typename Iterator::Ref Ref;
		typedef typename Iterator::Ptr Ptr;
		typedef ReverseListIterator<Iterator> Self;
	public:
		//////////////////////////////////////////////
		// 构造
		ReverseListIterator(Iterator it)
			:_it(it)
		{
		}

		//////////////////////////////////////////////
		// 指针操作
		Ref operator*()
		{
			Iterator temp(_it);
			--temp;
			return *temp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		//////////////////////////////////////////////
		// 迭代器移动操作
		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			++_it;
			return temp;
		}

		//////////////////////////////////////////////
		// 迭代器支持比较
		bool operator!=(const Self& l)const
		{
			return _it != l._it;
		}

		bool operator==(const Self& l)const
		{
			return _it == l._it;
		}

		Iterator _it;
	};


	template<class T>
	class list
	{
		typedef ListNode<T> Node;

	public:
		// 正向迭代器
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		// 反向迭代器
		typedef ReverseListIterator<iterator> reverse_iterator;
		typedef ReverseListIterator<const_iterator> const_reverse_iterator;
	public:
		///////////////////////////////////////////////////////////////
		// List的构造
		// 默认构造
		list()
		{
			CreateHead();
		}

		// 传值构造
		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}

		template<class Iterator>
		// 范围构造
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// 拷贝构造
		list(const list<T>& l)
		{
			CreateHead();
			list<T> temp(l.begin(), l.end());
			this->swap(temp);
		}

		list<T>& operator=(list<T> l)
		{
			this->swap(l);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		///////////////////////////////////////////////////////////////
		// List的迭代器
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(begin());
		}

		///////////////////////////////////////////////////////////////
		// List的容量相关
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t count = 0;

			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}

			return count;
		}

		bool empty()const
		{
			return _head->_next == _head;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize < oldsize)
			{
				while (newsize < oldsize)
				{
					pop_back();
					oldsize--;
				}
			}
			else
			{
				while (oldsize < newsize)
				{
					push_back(data);
					oldsize++;
				}
			}
		}

		////////////////////////////////////////////////////////////
		// List的元素访问操作
		// 注意：List不支持operator[]
		T& front()
		{
			return _head->_next->_val;
		}

		const T& front()const
		{
			return _head->_next->_val;
		}

		T& back()
		{
			return _head->_prev->_val;
		}

		const T& back()const
		{
			return _head->_prev->_val;
		}

		////////////////////////////////////////////////////////////
		// List的插入和删除
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			Node* pNewNode = new Node(val);
			Node* pCurNode = pos._node;

			pNewNode->_prev = pCurNode->_prev;
			pNewNode->_next = pCurNode;

			pNewNode->_prev->_next = pNewNode;
			pCurNode->_prev = pNewNode;

			return iterator(pNewNode);
		}

		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			Node* pDel = pos._node;
			Node* pRet = pDel->_next;

			pDel->_prev->_next = pDel->_next;
			pDel->_next->_prev = pDel->_prev;

			delete pDel;

			return iterator(pRet);
		}

		void clear()
		{
			Node* cur = _head->_next;

			while (_head->_next != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}

			_head->_next = _head->_prev = _head;
		}


		void swap(xiong::list<T>& l)
		{
			std::swap(_head, l._head);
		}

	private:
		void CreateHead()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}

	private:
		Node* _head;
	};
}

template <class T>
void PrintList(const xiong::list<T>& l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}