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
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		files.push_back(string(dirp->d_name));
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

	string dir; //
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
		string absoluteFile =(string(argv[1])+slash+filenames[i]).c_str();
		fin.open(absoluteFile);
		if (fin.fail())
		{
			cerr << "Couldn't open file " << filenames[i] << endl;
			exit(1);
		}
		//cout << filenames[i] << endl;
		while (fin >> next)
		{
			if (!words.find(next))
			{
				list<file> files;
				for (int n = 0; n < filenames.size(); n++)
				{
					absoluteFile =(string(argv[1])+slash+filenames[n]).c_str();
					file current(absoluteFile, next);
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
