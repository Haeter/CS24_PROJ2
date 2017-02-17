// Ryan Wiener, Porter Haet, 2/16/17

#ifndef list_h
#define list_h

#include <string>
using namespace std;

// nodes are used by the list class
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



// valueNode is used in map to manage collisions
template<typename K, typename V>
struct valueNode {
	K key;
	V value;
	valueNode* next;
	valueNode(K& initKey, V& initValue, valueNode<K, V> *initNext);
};


// map is used to improve performace by keeping track
// of each value in the list and its location in memory
template<typename K, typename V>
class map
{
	private:
		static const int MAX_SIZE = 500;
		valueNode<K, V>* keys[MAX_SIZE];
	public:
		map();
		void set(K k, V v);
		V get(K k);
};

// uses a map to make finding operations O(1)
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

		// returns a pointer to the data equal to the argument
		S* getDataPointer(S& data);
		
		// Allows for the traversal of the linked list
		void startIterating();
		S getCurrent();
		S* getCurrentPointer();
		void iterate();
		bool hasNext();
};

#include "list.cpp"

#endif // list_h
