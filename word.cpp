#include "word.h"

word::word()
{
	data = "";
	headptr = 0;
}

word::word(string dat, node<file> *head)
{
	data = dat;
	headptr = head;
}

string word::getWord()
{
	return data;
}

node<file>* word::getPtr()
{
	return headptr;
}
