#include "list.h"
#include "word.h"
#include "itemtype.h"
//using namespace std;

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
	length = 0;
}

template<class S>
int list<S>::getLength()
{
	return length;
}

template<class S>
int list<S>::find(string &data)
{
	int count = 0;
	node<word> *current = headptr;
	while (current)
	{
		if (current->getData().getWord() == data)
		{
			return count + 1;
		}
		else
		{
			current = current->getNext();
			count++;
		}
	}
	return 0;
}

template<class S>
node<S>* list<S>::getHeadptr()
{
	return headptr;
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
	length++;
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

template node<file>::node(file&);
template node<file>* node<file>::getNext();
template file node<file>::getData();
template void node<file>::setNext(node<file>* t);

template node<word>::node(word&);
template node<word>* node<word>::getNext();
template word node<word>::getData();
template void node<word>::setNext(node<word>* t);

template list<word>::list();
template int list<word>::getLength();
template int list<word>::find(string &data);
template node<word>* list<word>::getHeadptr();
template void list<word>::pushback(word&);
template word list<word>::get(int);

template list<file>::list();
template int list<file>::getLength();
template node<file>* list<file>::getHeadptr();
template void list<file>::pushback(file&);
template file list<file>::get(int);
