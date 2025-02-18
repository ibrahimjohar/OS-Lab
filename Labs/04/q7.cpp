#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
  pid_t pid = fork();

  if(pid == 0)
  {
    execlp("ls","ls","-l", NULL);
    cerr<<"excelp failed\n";
    return 1;
  }
  else
  {
    wait(NULL);
    cout<<"parent process. waiting for child process to terminate.\n";
  }

  return 0;
}
