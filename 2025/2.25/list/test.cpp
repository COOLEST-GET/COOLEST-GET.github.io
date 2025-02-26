#include <iostream>
#include <list>
#include "list.h"
using namespace std;

void print_list(const list<int>& lt) {
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

// 支持的操作接口的角度分迭代器的类型:单向(forword list)、双向(list)、随机(vector)
// 从使用的场景的角度分迭代器的类型 : (正向迭代器，反向迭代器)+const选代器

void test1() {
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	print_list(l1);

	list<int> l2(l1);
	print_list(l2);

	list<int> l3;
	l3.push_back(10);
	l3.push_back(20);
	l3.push_back(30);
	l3.push_back(40);

	l1 = l3;
	for (auto e : l1) {
		cout << e << " ";
	}
	cout << endl;


	list<int>::reverse_iterator rit = l3.rbegin();
	while (rit != l3.rend()) {
		cout << *rit << " ";
		rit++;
	}
}


void test2() {
	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	print_list(lt);

	lt.push_front(0);
	lt.push_front(-1);
	print_list(lt);

	lt.pop_front();
	lt.pop_back();
	print_list(lt);
}

void test3(){
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_back(7);


	print_list(lt);

	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end()) {
		lt.insert(pos, 10);
		lt.erase(pos);
	}
	print_list(lt);

	lt.sort();
	print_list(lt);
	lt.reverse();
	print_list(lt);
}

void test4() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_back(7);
	print_list(lt);

	list<int>::iterator it = lt.begin();
	while (it != lt.end()) {
		if (*it % 2 == 0) {
			it = lt.erase(it); // erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
		}
		else {
			it++;
		}
	}
	print_list(lt);
}


int main() {
	
	test4();



	return 0;
}