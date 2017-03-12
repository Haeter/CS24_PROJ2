#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
	BST<int> tester;
	tester.insert(1);
	tester.insert(4);
	tester.insert(22);
	tester.print();
	cout << endl;
	tester.insert(10);
	tester.insert(5);
	tester.print();
	cout << endl;
	int *fun = tester.get(22);
	if (fun)
	{
		cout << *fun << endl;
	}
	else
	{
		cout << fun << endl;
	}
	fun = tester.get(20);
	if (fun)
	{
		cout << *fun << endl;
	}
	else
	{
		cout << fun << endl;
	}
	return 0;
}
