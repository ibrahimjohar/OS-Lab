//ibrahim johar farooqi
//23k-0074
//bai-4a
//os lab - post lab - task 1

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "error: no numbers provided\n";
        cout << "usage: " << argv[0] << "<int1> <int2> ... <intN>\n";
        return 1;
    }

    vector<int> numbers;
    int sum = 0;

    for(int i = 1; i < argc; i++)
    {
        bool isnum = true;
        for(int j = 0; argv[i][j] != '\0'; j++)
        {
            if(!(argv[i][j] >= '0' && argv[i][j] <= '9') && !(argv[i][j] == '-' && j == 0))
            {
                isnum = false;
                break;
            }
        }
        
        if(!isnum) 
        {
            cout << "error: '" << argv[i] << "' is not valid integer\n";
            return 1;
        }
    
        int num = atoi(argv[i]); //string to int
        numbers.push_back(num);
        sum += num;
    }

    double average = static_cast<double>(sum) / numbers.size();

    cout << "numbers: ";
    for (int num : numbers) { cout << num << " "; }
    cout << "\nsum: " << sum;
    cout << "\nAverage: " << average << "\n";

    return 0;
}