#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void handlealarm(int signum)
{
  cout << "alarm received, program terminating now.\n";
  exit(0);
}

int main()
{
  signal(SIGALRM,handlealarm);
  alarm(5);
  cout << "alarm set, entering sleep loop now\n";
  int count = 1;
  
  while(true)
  {
    cout << "sleeping..." << count << " seconds elapsed.\n";
    sleep(1);
    count++;
  }

  return 0;
}
