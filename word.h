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
		list<file> files;
	public:
		word();
		word(string dat);
		string getWord();
		list<file>* getFiles();
};

#endif // word_h
