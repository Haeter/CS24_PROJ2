#include "itemtype.h"

file::file(string filename, int initCount)
{
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

bool file::operator==(const file& f) {
	return filename == f.filename;
}

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
