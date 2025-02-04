#include "WordCount.h"
#include <iostream>
#include <fstream>
using namespace std;

int WordCount::count_words(const string &filename)
{
    ifstream file1(filename);

    if (!file1) 
    {
        cout << "cant open file.\n";
        return -1;
    }

    string word;
    int wordCount = 0;
    while (file1 >> word)
    {
        wordCount++; //count words only (identified by whitespaces)
    }

    file1.close();

    return wordCount;
}
