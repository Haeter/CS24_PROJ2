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
	public:
		word(); // default constructor
		word(string dat); // parameter-driven constructor
		string getWord();
		list<file>* getFiles(); // returns a pointer to the list of files

		bool operator==(const word& other); // overload == operator for comparing word objects
		int getHashCode(); // return hash code for hashmap
};

#endif // word_h
