//ibrahim johar farooqi
//23k-0074
//bai-4a
//os lab - post lab - task 2

#include <iostream>
#include <vector>
#include <fstream>   
#include <algorithm> 
#include <cstdlib>   
using namespace std;

int missingnum(vector<int> &numbers)
{
    sort(numbers.begin(), numbers.end()); //sort

    for (int i = 0; i < numbers.size() - 1; i++) 
    {
        if (numbers[i] + 1 != numbers[i + 1])
        {
            return numbers[i] + 1; //missing num found
        }
    }
    return -1; //no missing num found
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    { 
        cout << "error: please provide a series that has atleast 2 numbers.\n";
        cout << "usage: " << argv[0] << " <int1> <int2> ... <intN>\n";
        return 1;
    }

    vector<int> numbers;

    for (int i = 1; i < argc; i++)
    {
        numbers.push_back(atoi(argv[i])); //string to integer
    }

    int missing = missingnum(numbers);

    //write missing num to file
    ofstream outputfile("output.txt");
    if (!outputfile) 
    {
        cout << "couldnt open file for writing.\n";
        return 1;
    }

    if (missing == -1) 
    {
        outputfile << "no missing number found in sequence.\n";
        cout << "no missing number found.\n";
    } 
    else
    {
        outputfile << "missing number: " << missing << "\n";
        cout << "missing number found & saved in output.txt: " << missing << "\n";
    }

    outputfile.close();
    return 0;
}
