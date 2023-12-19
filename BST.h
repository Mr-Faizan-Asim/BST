#pragma once
#include"Node.h"
#include<iostream>
#include<queue>

using namespace std;
template <typename T>
class BST
{
	Node<T>* root;
	int numberofEdges;
public:
	BST() { root = nullptr; }
	// insert without root
	void insert(T data)
	{
		Node<T>* node = new Node<T>(data);
		insertion(root, data);
		
	}
	//insert with root as parameter  use & this to pass it by reference
	void insertion(Node<T>* &node,T data)
	{
		if (node == nullptr)
		{
			node = new Node<T>(data);
			return;
		}
		if (node->data < data) {
			insertion(node->right, data);
		}
		else
		{
			insertion(node->left, data);
		}
	}
	// Simple Print By order
	void print()
	{
		levelOrder(root);
	}
	// Print BST by Choice()
	void print(int way)
	{
		if (way == 1)
		{
			inorder(root);
		}
		else if (way == 2)
		{
			preorder(root);
		}
		else if(way == 3)
		{
			postorder(root);
		}
	}
	// inorder traversel
	void inorder(Node<T>* node)
	{
		if (node == nullptr)
			return;
		inorder(node->left);
		cout << node->data<< " ";
		inorder(node->right);

	}
	// postorder print
	void preorder(Node<T>* node)
	{
		if (node == nullptr)
			return;
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}
	// post order print
	void postorder(Node<T>* node)
	{
		if (node == nullptr)
			return;

		postorder(node->left);
		postorder(node->right);
		cout << node->data << " ";
	}
	// level order Traversal
	void levelOrder(Node<T>* node)
	{
		queue<Node<T>*> tempQue;
		tempQue.push(node);
		while (tempQue.empty() == false)
		{
			Node<T>* node = tempQue.front();
			cout << node->data << " ";
			tempQue.pop();
			if (node->left != nullptr)
				tempQue.push(node->left);
			if (node->right != nullptr)
				tempQue.push(node->right);
		}
	}
	// Heap Sort
	void heapSort(T arr[],int size)
	{
		int n = size;
		// This loop is used to creat a max heap tree or array
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i);
		}
		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}
	// heapify {1,3,4,5,10} it runs untill i become the largest
	void heapify(T arr[],int n, int i)
	{
		int largest = i;
		int  l = 2 * i + 1;
		int  r = 2 * i + 2;
		if (l < n && arr[l] > arr[largest])
			largest = l;
		if (r < n && arr[r] > arr[largest])
			largest = r;
		
		if (largest != i)
		{
			swap(arr[i], arr[largest]);
			heapify(arr, n, largest);
		}

	}
};

