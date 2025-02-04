//ibrahim johar farooqi
//23k-0074
//bai-4a
//os lab - inlab - task 3

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "usage: " << argv[0] << " <int1> <int2> ... <intn>\n";
    return 1; //exit w/ error
  }
  vector<int> numbers;
  
  for(int i =1; i < argc; i++)
  {
    numbers.push_back(atoi(argv[i])); //string to int
  }
  
  int temp;
  for(int i = 0; i < numbers.size(); i++)
  {
    for(int j = 0; j < numbers.size() - 1 - i; j++)
    {
      if(numbers[j] > numbers[j+1])
      {
          temp = numbers[j];
          numbers[j] = numbers[j+1];
          numbers[j+1] = temp;
      }
    }
  }
  
  cout << "sorted numbers: ";
  for(int num: numbers)
  {
    cout << num << " ";
  }
  cout << "\n";

  return 0;
}
