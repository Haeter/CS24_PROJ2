// Ryan Wiener, Porter Haet, 2/16/17

#ifndef word_h
#define word_h

#include <string>
#include "list.h"
#include "itemtype.h"
using namespace std;
class word
{
	// word contains a string and a list of files
	private:
		string data;
		list<file> files;
		struct node {
			word* left, *right;
			node(word* left = 0, word* right = 0) {
				this->left = left;
				this->right = right;
			}
		};
		node n;
		int totalCount;
	public:
		word(); // default constructor
		word(string dat); // parameter-driven constructor
		word* getLeft();
		word* getRight();
		void insert(word* w);
		string getWord();
		word* get(string dat);

		list<file>* getFiles(); // returns a pointer to the list of files
		void incrementTotalCount();

		bool operator==(const word& other); // overload == operator for comparing word objects
		int getHashCode(); // return hash code for hashmap

		int getFileTotal();
		int getWordTotal();
		double getWordAverage();
		void print(int &numWords);
};

#endif // word_h
