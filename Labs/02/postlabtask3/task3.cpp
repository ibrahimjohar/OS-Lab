//ibrahim johar farooqi
//23k-0074
//bai-4a
//os lab - post lab - task 3

#include <iostream>
#include <vector>
#include <fstream>   
#include <algorithm> 
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

int main() 
{
    string filename;
    cout << "enter filename: ";
    cin >> filename;

    ifstream file1(filename);
    if (!file1) 
    {
        cout << "file not found or cant be opened.\n";
        return 1;
    }

    vector<int> numbers;
    int num;

    //read file
    while (file1 >> num) 
    {
        numbers.push_back(num);
    }
    file1.close();

    if (numbers.size() < 2)
    { 
        cout << "insufficient numbers in the file.\n";
        return 1;
    }

    int missing = missingnum(numbers);

    ofstream file2("output.txt");
    if (!file2) 
    {
        cout << "couldnt open file for writing.\n";
        return 1;
    }

    if (missing == -1) 
    {
        file2 << "no missing number found in sequence.\n";
        cout << "no missing number found.\n";
    } 
    else
    {
        file2 << "missing number: " << missing << "\n";
        cout << "missing number found & saved in output.txt: " << missing << "\n";
    }

    file2.close();
    return 0;
}