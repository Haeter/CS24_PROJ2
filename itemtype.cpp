#include "itemtype.h"

file::file(string filename, string word)
{
	count = 0;
	this->filename = filename;
	ifstream fin;
	fin.open(filename.c_str());
	if (fin.fail())
	{
		cerr << "File " << filename << " couldn't be opened.";
		exit(1);
	}
	string next;
	while (fin >> next)
	{
		if (next == word)
		{
			count++;
		}
	}
	fin.close();
}

string file::getFilename()
{
	return filename;
}

int file::getCount()
{
	return count;
}
