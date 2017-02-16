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
	list<word> words;
	string next;
	string slash = "/";
	int wordsRecorded = 0;

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
			/*word* currentWord = NULL;
			for (words.startIterating(); words.hasNext(); words.iterate()) {
				currentWord = words.getCurrentPointer();
				if (currentWord->getWord() == next) {
					break;
				}
			}*/

			///////////////////////////
			//unordered_map<string, int>::iterator it = seen.find(next);
			for (int i = 0; i < next.length(); i++)
			{
				if(ispunct(next[i]))
				{
					next.erase(i, 1);
				}
				else
				{
					next[i] = tolower(next[i]);
				}
			}
			cout << next << endl;
			word newWord(next);
			word* currentWord = words.getDataPointer(newWord);
			if (currentWord)
			{
				list<file>* filesWithWord = currentWord->getFiles();
				//bool matched = false;
				file newFile(filenames[i], 1);
				file* fileWithWord = filesWithWord->getDataPointer(newFile);
				if (fileWithWord)
				{
					fileWithWord->setCount(fileWithWord->getCount() + 1);
				}
				else
				{
					currentWord->getFiles()->pushfront(newFile);
				}
				/*
				for (filesWithWord->startIterating(); filesWithWord->hasNext(); filesWithWord->iterate())
				{
					fileWithWord = filesWithWord->getCurrentPointer();
					if (fileWithWord->getFilename() == filenames[i])
					{
						matched = true;
						fileWithWord->setCount(fileWithWord->getCount() + 1);
						break;
					}
				}
				if (!matched)
				{
					file newFile(filenames[i], 1);
					currentWord->getFiles()->pushfront(newFile);
				}
				*/
			}
			else
			{
				file newFile(filenames[i], 1);
				newWord.getFiles()->pushfront(newFile);
				words.pushfront(newWord);
				wordsRecorded++;
			}

			/*
			if (it == seen.end()) {
				currentWord = NULL;
			}
			else {
				int i = 0, max = wordsRecorded - it->second - 1;
				for (words.startIterating(); i < max; words.iterate()) {
					i++;
				}
				currentWord = words.getCurrentPointer();
			}
			*/
			///////////////////////////
			/*			
			if (currentWord && currentWord->getWord() == next)
			{
				list<file>* filesWithWord = currentWord->getFiles();
				bool matched = false;
				file* fileWithWord;
				for (filesWithWord->startIterating(); filesWithWord->hasNext(); filesWithWord->iterate())
				{
					fileWithWord = filesWithWord->getCurrentPointer();
					if (fileWithWord->getFilename() == filenames[i])
					{
						matched = true;
						fileWithWord->setCount(fileWithWord->getCount() + 1);
						break;
					}
				}
				if (!matched)
				{
					file newFile(filenames[i], 1);
					currentWord->getFiles()->pushfront(newFile);
				}
			}
			else
			{
				file newFile(filenames[i], 1);
				word newWord(next);
				newWord.getFiles()->pushfront(newFile);

				words.pushfront(newWord);
				seen[next] = wordsRecorded;
				wordsRecorded++;
			}
			*/
		}
		fin.close();
	}
	string input;
	cout << "Enter word: ";
	cin >> input;
	while (input != "exit")
	{
		word search(input);
		word* currentWord = words.getDataPointer(search);
		if (currentWord)
		{
			/*
			list<file>* filesWithWord = currentWord->getFiles();
		for (words.startIterating(); words.hasNext(); words.iterate()) {
			search = words.getCurrent();
			if (search.getWord() == input) {
				break;
			}
		}
		*/
			printResults(*currentWord);
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
	list<file> files = *(current.getFiles());
	for (int i = 0; i < files.length(); i++) {
		file f = files.get(i);
		cout << f.getFilename() << " " << f.getCount() << endl;
	}
}
