#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream input_file("input.txt");
  ofstream output_file("output.txt");
  if(!input_file)
  {
    cerr << "error: unable to open input file!\n";
    return 1;
  }
  if(!output_file)
  {
    cerr << "error: unable to open output file!\n";
    return 1;
  }
  
  string line;
  
  while(getline(input_file,line))
  {
    output_file<<line<<"\n";
  }

  input_file.close();
  output_file.close();

  cout<<"file copied successfully\n";
  
  return 0;
}
