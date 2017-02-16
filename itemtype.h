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
		file(string filename, int initCount);
		string getFilename();
		int getCount();
		void setCount(int newCount);

		bool operator==(const file&f);
		int getHashCode();
};

#endif // itemtype_h
