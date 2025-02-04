#include "LineCount.h"
#include <iostream>
#include <fstream>
using namespace std;

int LineCount::count_lines(const string &filename) 
{
    ifstream file1(filename);

    if (!file1) 
    {
        cout << "cant open file.\n";
        return -1;
    }

    string line;
    int lineCount = 0;
    
    while (getline(file1, line))
    {
        lineCount++; //counting every line
    }

    file1.close();

    return lineCount;
}
