#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"
#include "word.h"
#include "itemtype.h"
//using namespace std;

template<typename T>
node<T>::node(T &d, node<T>* n) : data(d), next(n)
{
}


template<typename T>
T node<T>::getData()
{
	return this->data;
}

template<typename T>
T* node<T>::getDataPointer()
{
	return &(this->data);
}

template<typename T>
node<T>* node<T>::getNext()
{
	return this->next;
}

template<typename T>
void node<T>::setNext(node<T>* n)
{
	this->next = n;
}

template<typename S>
list<S>::list()
{
	headptr = NULL;
	len = 0;
}

template<class S>
int list<S>::length()
{
	return len;
}

template<typename S>
void list<S>::pushfront(S& data) {
	headptr = new node<S>(data, headptr);
	len++;
}

template<typename S>
S list<S>::get(int index) {
	node<S> *current = headptr;
	for (int i = 0; i < index && current; i++)
	{
		current = current->getNext();
	}
	return current->getData();
}

template<typename S>
void list<S>::startIterating() {
	iter = headptr;
}

template<typename S>
void list<S>::iterate() {
	iter = iter->getNext();
}

template<typename S>
S list<S>::getCurrent() {
	return iter->getData();
}

template<typename S>
S* list<S>::getCurrentPointer() {
	return iter->getDataPointer();
}
template<typename S>
bool list<S>::hasNext() {
	return iter != NULL;
}



/*
template node<file>::node(file&, node<file>*);
template node<file>* node<file>::getNext();
template file node<file>::getData();
template void node<file>::setNext(node<file>* t);

template node<word>::node(word&, node<word>*);
template node<word>* node<word>::getNext();
template word node<word>::getData();
template void node<word>::setNext(node<word>* t);

template list<word>::list();
template int list<word>::length();
template int list<word>::find(string &data);
template void list<word>::pushfront(word&);
template word list<word>::get(int);

template list<file>::list();
template int list<file>::length();
template void list<file>::pushfront(file&);
template file list<file>::get(int); */

#endif
