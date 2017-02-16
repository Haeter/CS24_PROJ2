#ifndef list_h
#define list_h

#include <string>
using namespace std;


template<typename T>
class node
{
	private:
		T data;
		node<T> *next;
	public:
		node(T& data, node<T>* n=NULL);
		T getData();
		T* getDataPointer();
		node<T>* getNext();
		void setNext(node<T>* n);
};



template<typename K, typename V>
struct valueNode {
	K key;
	V value;
	valueNode* next;
};


template<typename K, typename V>
class map
{
	private:
//		const int MAX_SIZE;
		valueNode<V, K>* keys[1000];
	public:
		void set(K k, V v);
		V get(K k);
};


template<typename S>
class list
{
	private:
		node<S> *headptr, *iter;
		int len;
	public:
		list();
		int length();
		void pushfront(S& data);
		S get(int index);

		void startIterating();
		S getCurrent();
		S* getCurrentPointer();
		void iterate();
		bool hasNext();
};

#include "list.cpp"

#endif // list_h
