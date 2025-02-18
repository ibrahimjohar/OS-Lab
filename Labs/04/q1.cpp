#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
  pid_t child1, child2;
  child1 = fork();
  
  if(child1 == 0)
  {
    cout << "child 1: my pid is " << getpid() << "\n";
    return 0;
  }
  
  child2 = fork();
  if(child2 == 0)
  {
    cout << "child 2: my parent pid is "<< getppid() << "\n";
    return 0;
  }
  
  wait(NULL);
  wait(NULL);
  cout << "parent :  both child processes have been terminated\n";
  
  return 0;
}
