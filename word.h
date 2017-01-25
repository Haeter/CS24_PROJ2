#ifndef word_h
#define word_h

#include <string>
#include "list.h"
#include "itemtype.h"
using namespace std;
class word
{
	private:
		string data;
		node<file> *headptr;
	public:
		word();
		word(string dat, node<file>* head);
		string getWord();
		node<file>* getPtr();
};

#endif // word_h
