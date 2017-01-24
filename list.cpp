#include "list.h"
#include "word.h"
#include "itemtype.h"
using namespace std;

template<typename T>
node<T>::node(T &d) : data(d)
{
	next = 0;
}


template<typename T>
T node<T>::getData()
{
	return this->data;
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
	headptr = last = 0;
}

template<typename S>
void list<S>::pushback(S& data) {
	node<S> *n = new node<S>(data);
	if (!headptr) {
		headptr = last = n;
	}
	else {
		last->setNext(n);
		last = n;
	}
}

template<typename S>
S list<S>::get(int index) {
	return headptr->getData();
}

template node<file>::node(file&);
template node<file>* node<file>::getNext();
template file node<file>::getData();
template void node<file>::setNext(node<file>* t);

template node<word>::node(word&);
template node<word>* node<word>::getNext();
template word node<word>::getData();
template void node<word>::setNext(node<word>* t);

template list<word>::list();
template void list<word>::pushback(word&);
template word list<word>::get(int);

template list<file>::list();
template void list<file>::pushback(file&);
template file list<file>::get(int);
