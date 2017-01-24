#ifndef list_h
#define list_h

template<typename T>
class node
{
	private:
		T data;
		node<T> *next;
	public:
		node(T& data);
		T getData();
		node<T>* getNext();
		void setNext(node<T>* n);
};

template<typename S>
class list
{
	private:
		node<S> *headptr, *last;
	public:
		list();
		void pushback(S& data);
		S get(int index);
};

#endif // list_h
