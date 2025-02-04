#include "LetterCount.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int LetterCount::count_letters(const string &filename) 
{
    ifstream file1(filename);
    if (!file1) 
    {
        cout << "cant open file.\n";
        return -1;
    }

    char ch;
    int letterCount = 0;
    while (file1.get(ch))
    {
        if (isalpha(ch)) letterCount++; //only count letters
    }

    file1.close();
    
    return letterCount;
}
