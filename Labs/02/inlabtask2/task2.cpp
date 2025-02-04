#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	int temp = atoi(argv[1]);
	
	for (int i = 1; i < argc; i++)
	{
		int curr = atoi(argv[i]);
		
		if(curr != temp)
		{
			cout << "missing element: " <<  temp << "\n";
			return 0;
		}
		
		temp++;
	}
	
	cout << "no missing element!\n";
	return 1;
}
