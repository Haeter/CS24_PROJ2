#include <vector>
#include <dirent.h>
#include "wordsearch.h"
using namespace std;



// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir.c_str())) == NULL) {
		cout << "Error opening " << dir << endl;
		return 1;
	}
	while ((dirp = readdir(dp)) != NULL) {
		if (string(dirp->d_name)[0] != '.')
		{
			files.push_back(string(dirp->d_name));
		}
	}
	closedir(dp);
	return 0;
}


int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "No directory inputted.\nUsage: ./wordsearch directory ...\n";
		exit(1);
	}

	string dir;
	vector<string> filenames;

	dir = string(argv[1]);
	if (getdir(dir,filenames)!=0) {
		cout << "Error opening " << dir << "; Exiting ..." << endl;
		return(-2);
    }

	ifstream fin;
	list<word> words;
	string next;
	string slash = "/";
	for (int i = 0; i < filenames.size(); i++)
	{
		string absoluteFile =(string(argv[1])+slash+filenames[i]);
		cout << absoluteFile << endl;
		fin.open(absoluteFile.c_str());
		if (fin.fail())
		{
			cerr << "Couldn't open file " << filenames[i] << endl;
			exit(1);
		}
		//cout << filenames[i] << endl;
		while (fin >> next)
		{
			cout << next << endl;
			int index(0);
			if (index = words.find(next))
			{
				word currentWord = words.get(index);
				node<file> *currentFile = currentWord.getPtr();
				node<file> *previousFile = currentFile;
				while (currentFile)
				{
					if (currentFile->getData().getFilename() == filenames[i])
					{
						cout << currentFile->getData().getFilename() << endl;
						currentFile->getData().setCount(currentFile->getData().getCount() + 1);
						break;
					}
					previousFile = currentFile;
					currentFile = currentFile->getNext();
				}
				if (!currentFile)
				{
					file newFile(filenames[i], 1);
					node<file> *filePtr = new node<file>(newFile);
					previousFile->setNext(filePtr);
				}
			}
			else
			{
				file newFile(filenames[i], 1);
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
