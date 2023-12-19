#pragma once
template <typename T>
class Node
{
public:
	Node<T>* left;
	Node<T>* right;
	T data;
	Node(T data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

};

