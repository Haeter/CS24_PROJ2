// Ryan Wiener, Porter Haet, 2/16/17

#include "word.h"

word::word()
{
	data = "";
}

word::word(string dat)
{
	data = dat;
}

string word::getWord()
{
	return data;
}

list<file>* word::getFiles() {
	return &files; 
}

bool word::operator==(const word& other) {
	return data == other.data; // only compare the string and not the list of files
}

int word::getHashCode() {
	int code = 0;
	// only hash the first four characters
	for (int i = 0; i < 4 && i < data.length(); i++) {
		int twentysix = 26;
		for (int n = 0; n < i; n++) { twentysix *= 26; }

		code += twentysix * (data[i] % 26);
	}
	return code;
}
