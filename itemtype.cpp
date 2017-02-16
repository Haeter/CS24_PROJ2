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
