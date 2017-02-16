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
	return 1;
}
