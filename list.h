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
	valueNode(K& initKey, V& initValue, valueNode<K, V> *initNext);
};


template<typename K, typename V>
class map
{
	private:
		static const int MAX_SIZE = 1000;
		valueNode<K, V>* keys[MAX_SIZE];
	public:
		void set(K k, V v);
		V get(K k);
};


template<typename S>
class list
{
	private:
		node<S> *headptr, *iter;
		map<S, node<S>* > hashMap;
		int len;
	public:
		list();
		int length();
		void pushfront(S& data);
		S get(int index);
		S* getDataPointer(S& data);
		void startIterating();
		S getCurrent();
		S* getCurrentPointer();
		void iterate();
		bool hasNext();
};

#include "list.cpp"

#endif // list_h
