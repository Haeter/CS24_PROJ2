#include "wordsearch.h"
using namespace std;
int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "No files input.\nUsage: ./wordsearch filepath1 filepath2 ...\n";
		exit(1);
	}
	ifstream fin;
	list<word> words;
	string next;
	for (int i = 1; i < argc; i++)
	{
		fin.open(argv[i]);
		if (fin.fail())
		{
			cerr << "Couldn't open file " << argv[i] << endl;
			exit(1);
		}
		while (fin >> next)
		{
			if (!words.find(next))
			{
				list<file> files;
				for (int i = 1; i < argc; i++)
				{
					file current(argv[i], next);
					if (current.getCount() > 0)
					{
						files.pushback(current);
					}
				}
				if (files.getLength() > 0)
				{
					word current(next, files.getHeadptr());
					words.pushback(current);
				}
			}
		}
		fin.close();
	}
	string input;
	cout << "Enter word: ";
	cin >> input;
	while (input != "exit")
	{
		int index = words.find(input);
		if (index)
		{
			printResults(words.get(index - 1));
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
