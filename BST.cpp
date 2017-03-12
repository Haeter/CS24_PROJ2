#ifndef BST_cpp
#define BST_cpp

#include "BST.h"

template<typename T>
template<typename S>
BST<T>::node<S>::node()
{
	left = 0;
	right = 0;
}

template<typename T>
template<typename S>
S* BST<T>::node<S>::getDataPointer()
{
	return &value;
}

template<typename T>
BST<T>::BST()
{
	treeRoot = 0;
}

template<typename T>
void BST<T>::insert(T val)
{
	if (!treeRoot)
	{
		treeRoot = new node<T>;
		treeRoot->value = val;
		return;
	}
	insert(val, treeRoot);
}

template<typename T>
void BST<T>::insert(T val, node<T>* root)
{
	if (val > root->value)
	{
		if (root->right)
		{
			insert(val, root->right);
		}
		else
		{
			node<T> *newNode = new node<T>;
			newNode->value = val;
			root->right = newNode;
		}
	}
	else if (val < root->value)
	{
		if (root->left)
		{
			insert(val, root->left);
		}
		else
		{
			node<T> *newNode = new node<T>;
			newNode->value = val;
			root->left = newNode;
		}
	}
}

template<typename T>
T* BST<T>::get(T val)
{
	return get(val, treeRoot);
}

template<typename T>
T* BST<T>::get(T val, node<T>* root)
{
	if (!root)
	{
		return 0;
	}
	if (val == root->value)
	{
		return root->getDataPointer();
	}
	if (val < root->value)
	{
		return get(val, root->left);
	}
	return get(val, root->right);
}

template<typename T>
void BST<T>::print()
{
	print(treeRoot);
}

template<typename T>
void BST<T>::print(node<T> *root)
{
	if (!root)
	{
		return;
	}
	print(root->left);
	cout << root->value << endl;
	print(root->right);
}

#endif
