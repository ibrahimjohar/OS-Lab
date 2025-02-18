#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main()
{
  pid_t pid = fork();

  if(pid<0)
  {
    cerr << "fork failed\n";
    return 1;
  }
  else if(pid == 0)
  {
    for(int i = 0; i < 100; i++)
    {
      cout << "i am a child process.\n";
    }
  }
  else
  {
    for(int i = 0; i < 100; i++)
    {
      cout << "i am a parent process.\n";
    }
    wait(NULL);
  }
  
  return 0;
}

