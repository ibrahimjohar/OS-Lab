#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
  pid_t pid = fork();
  if(pid == 0)
  {
    cout << "child process: listing all files in directory: " << "\n";
    execlp("ls","ls","-l", NULL);

    cerr << "excelp failed\n";
    return 1;
  }
  else
  {
    wait(NULL);
    cout << "parent process: child process has terminated\n";
  }

  return 0;
}
