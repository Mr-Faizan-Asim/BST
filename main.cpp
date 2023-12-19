#include <iostream>
#include "BST.h"
using namespace std;


int main()
{
	BST<int>* a = new BST<int>();
	int arr[] = { 1,3,4,10,11 };
	a->insert(2);
	a->insert(1);
	a->insert(3);
	a->insert(6);
	a->insert(8);
	a->insert(11);
	a->print();
	a->heapSort(arr,5);
	for (int a : arr)
	{
		cout << a << " ";
	}	
}

