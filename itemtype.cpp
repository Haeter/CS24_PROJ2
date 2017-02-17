// Ryan Wiener, Porter Haet, 2/16/17

#include "itemtype.h"

file::file(string filename, int initCount)
{
	// initializes the file 
	count = initCount;
	this->filename = filename;
}

string file::getFilename()
{
	return filename;
}

int file::getCount()
{
	return count;
}

void file::setCount(int newCount)
{
	count = newCount;
}

// files are equal if their filenames are equal
bool file::operator==(const file& f) {
	return filename == f.filename;
}

// hashCode is used for the hash map in the linked list
// The hash result is based on the first 4 characters of the file name
int file::getHashCode() {
	int code = 0;
	// only hash the first four characters
	for (int i = 0; i < 4 && i < filename.length(); i++) {
		int twentysix = 26;
		for (int n = 0; n < i; n++) { twentysix *= 26; }

		code += twentysix * (filename[i] % 26);
	}
	return code;
}
