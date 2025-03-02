#include "list.h"


// 测试List的构造
void TestBiteList1()
{
	xiong::list<int> l1;
	xiong::list<int> l2(10, 5);
	PrintList(l2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	xiong::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);

	xiong::list<int> l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
}

// PushBack()/PopBack()/PushFront()/PopFront()
void TestBiteList2()
{
	// 测试PushBack与PopBack
	xiong::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	PrintList(l);

	l.pop_back();
	l.pop_back();
	PrintList(l);

	l.pop_back();
	cout << l.size() << endl;

	// 测试PushFront与PopFront
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	PrintList(l);

	l.pop_front();
	l.pop_front();
	PrintList(l);

	l.pop_front();
	cout << l.size() << endl;
}

// 测试insert和erase
void TestBiteList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	xiong::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto pos = l.begin();
	l.insert(l.begin(), 0);
	PrintList(l);

	++pos;
	l.insert(pos, 2);
	PrintList(l);

	l.erase(l.begin());
	l.erase(pos);
	PrintList(l);

	// pos指向的节点已经被删除，pos迭代器失效
	cout << *pos << endl;

	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	cout << l.size() << endl;
}

// 测试反向迭代器
void TestBiteList4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	xiong::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const xiong::list<int> cl(l);
	auto crit = l.rbegin();
	while (crit != l.rend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}



int main()
{
	//TestBiteList1();
	//TestBiteList2();
	//TestBiteList3();
	//TestBiteList4();

	return 0;
}