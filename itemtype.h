// Ryan Wiener, Porter Haet, 2/16/17

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

		// These functions are required for use in the hashmap
		bool operator==(const file&f);
		int getHashCode();
};

#endif // itemtype_h
