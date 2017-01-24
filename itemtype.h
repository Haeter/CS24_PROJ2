#ifndef itemtype_h
#define itemtype_h

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
class file{
	private:
		string filename;
		int count;
	public:
		file(string filename, string word);
		string getFilename();
		int getCount();
};

#endif // itemtype_h
