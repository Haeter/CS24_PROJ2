#include "wordsearch.h"
using namespace std;
int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "No files input.\nUsage: ./wordsearch filepath1 filepath2 ...\n";
		exit(1);
	}
	string input;
	cout << "Enter word: ";
	cin >> input;
	list<word> words;
	while (input != "exit")
	{
		list<file> files;
		for (int i = 1; i < argc; i++)
		{
			file current(argv[i], input);
			if (current.getCount() > 0)
			{
				files.pushback(current);
			}
		}
		if (files.getLength() > 0)
		{
			word current(input, files.getHeadptr());
			words.pushback(current);
			printResults(current);
		}
		else
		{
			cout << "No results found.\n";
		}
		cout << "Enter word: ";
		cin >> input;
	}
	return 0;
}

void printResults(word current)
{
	node<file> *p = current.getPtr();
	while (p) {
		file f = p->getData();
		cout << f.getFilename() << " " << f.getCount() << endl;
		p = p->getNext();
	}
}
