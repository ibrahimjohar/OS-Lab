#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
  pid_t pid = getpid();
  cout << "current process id: "<< pid << "\n";

  pid_t ppid= getppid();
  cout<<"parent process id: "<< ppid << "\n";

  uid_t uid = getuid();
  cout<<"user id: "<< uid << "\n";

  return 0;
}
