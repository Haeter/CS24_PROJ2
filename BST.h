// Ryan Wiener, Porter Haet, 3/12/17
#ifndef BST_h
#define BST_h

#include <iostream>
using namespace std;

template<typename T>
class BST
{
	public:
		BST();
		void insert(T val);
		T* get(T val);
		void print();
	private:
		template<typename S>
		struct node
		{
			S value;
			node *left;
			node *right;
			node();
			S* getDataPointer();
		};
		node<T> *treeRoot;
		void print(node<T>* root);
		void insert(T val, node<T>* root);
		T* get(T val, node<T>* root);
};

#include "BST.cpp"

#endif
