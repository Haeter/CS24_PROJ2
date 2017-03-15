// Ryan Wiener, Porter Haet, 2/16/17

#include <vector>
#include <dirent.h>
#include <cctype>
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
	word* root = NULL; // root of word tree
	string next;
	string slash = "/";

	for (int i = 0; i < filenames.size(); i++)
	{
		string absoluteFile =(string(argv[1])+slash+filenames[i]);
		fin.open(absoluteFile.c_str());
		if (fin.fail())
		{
			cerr << "Couldn't open file " << filenames[i] << endl;
			exit(1);
		}
		cout << filenames[i] << endl;
		while (fin >> next)
		{
			for (int j = 0; j < next.length(); j++)
			{
				// gets rid of punctuation and makes lowercase
				char ch = next[j];
				if(ispunct(ch) || ch == '"' || isspace(ch) || isdigit(ch))
				{
					next.erase(j, 1);
					j--;
				}
				else
				{
					next[j] = tolower(next[j]);
				}
			}
			if (next == "") { continue; }
			if (!root) {
				root = new word(next);
			}

			//cout << next << endl;
			word* currentWord = root->get(next);
			if (currentWord) // checks if word was found
			{
//				cout << next << " found" << endl;
				list<file>* filesWithWord = currentWord->getFiles();
				file newFile(filenames[i], 1);
				file* fileWithWord = filesWithWord->getDataPointer(newFile); // gets pointer to word in list or returns NULL if not found
				if (fileWithWord) // checks if file was found
				{
					fileWithWord->setCount(fileWithWord->getCount() + 1); // increments count by 1 in file
				}
				else
				{
					currentWord->getFiles()->pushfront(newFile); // push new file object
				}
				currentWord->incrementTotalCount();
			}
			else
			{
				//cout << next << " not found" << endl;
				word* newWord = new word(next);
				// create new word object and append to list of words
				file newFile(filenames[i], 1);
				newWord->getFiles()->pushfront(newFile);
				root->insert(newWord);
				newWord->incrementTotalCount();
			}
//			cout << "printing ---------------" << endl;
//			root->print();
//			cout << "---------" << endl;

		}
		fin.close();
	}
	int mode = 0;
	cout << "Enter mode (1 for word search, 2 for word sort, or 0 to quit): ";
	cin >> mode;
	while (mode < 0 || mode > 2)
	{
		cout << "Invalid mode entry" << endl;
		cout << "Enter mode (1 for word search, 2 for word sort, or 0 to quit): ";
		cin >> mode;
	}
	while (mode == 1 || mode == 2)
	{
		if (mode == 1)
		{
			string input;
			cout << "Enter word (or exit to quit): ";
			cin >> input;
			if (input != "exit")
			{
				for (int i = 0; i < input.length(); i++)
				{
					// gets rid of punctuation and makes lowercase
					if(ispunct(input[i]) || next[i] == '"')
					{
						input.erase(i, 1);
						i--;
					}
					else
					{
						input[i] = tolower(input[i]);
					}
				}
				word* currentWord = root->get(input);
				if (currentWord) // checks to see if word was found
				{
					printResults(*currentWord);
				}
				else
				{
					cout << "No results found.\n";
				}
				/*
				cout << "Enter word: ";
				cin >> input;
				*/
			}
		}
		else
		{
			int numWords;
			cout << "Enter how many words to print (or a negative number to quit): ";
			cin >> numWords;
			if (numWords >= 0)
			{
				root->print(numWords);
			}
		}
		cout << "Enter mode (1 for word search, 2 for word sort, or 0 to quit): ";
		cin >> mode;
		while (mode < 0 || mode > 2)
		{
			cout << "Invalid mode entry" << endl;
			cout << "Enter mode (1 for word search, 2 for word sort, or 0 to quit): ";
			cin >> mode;
		}
	}
	return 0;
}

void printResults(word current)
{
	cout << "Filename Count" << endl;
	list<file> files = *(current.getFiles());
	for (int i = files.length() - 1; i >= 0; i--) {
		file f = files.get(i);
		cout << f.getFilename() << " " << f.getCount() << endl; // print out filename and count
	}
	cout << "Word Total " << current.getWordTotal() << endl;
	cout << "File Total " << current.getFileTotal() << endl;
	cout << "Average " << current.getWordAverage() << endl;
}
