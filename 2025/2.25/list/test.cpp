#include <iostream>
#include <list>
using namespace std;

int main() {
	
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	list<int>::iterator it = l1.begin();
	while (it != l1.end()) {
		cout << *it << " " << endl;
		it++;
	}



	return 0;
}