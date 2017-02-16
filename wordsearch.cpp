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
			cout << next << endl;
			if (words.find(next))
			{
				word currentWord = words.get(words.find(next));
				node<file> *currentFile = currentWord.getPtr();
				node<file> *previousFile = NULL;
				while (currentFile)
				{
					if (strcmp(currentFile->getData().getFilename().c_str(), argv[i]) == 0)
					{
						currentFile->getData().setCount(currentFile->getData().getCount() + 1);
						break;
					}
					previousFile = currentFile;
					currentFile = currentFile->getNext();
				}
				if (!currentFile)
				{
					file newFile(argv[i], 1);
					node<file> *filePtr = new node<file>(newFile);
					previousFile->setNext(filePtr);
				}
			}
			else
			{
				file newFile(argv[i], 1);
				node<file> *filePtr = new node<file>(newFile);
				word currentWord(next, filePtr);
				words.pushback(currentWord);
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
