// Now, use signal (SIGUSR1, my_handler); with appropriate my_handler function to place a user defined signal
// and its handler in your code. Raise the signal with kill (pid, SIGUSR1);

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

//our user defined signal handler
void my_handler(int signum)
{
    //signum will be SIGUSR1 (usually 10 on linux)
    printf("my_handler: caught user-defined signal %d\n", signum);
}

int main(int argc, char argv[])
{
    pid_t pid = getpid(); //get our own process ID

    //register my_handler to run when SIGUSR1 is received 
    if (signal(SIGUSR1, my_handler) == SIG_ERR)
    {
        perror("signal");
        exit(1);
    }

    printf("process pid = %d\n", pid);
    printf("raising SIGUSR1 to self...\n");

    //send SIGUSR1 to this process 
    if (kill(pid, SIGUSR1) != 0)
    {
        perror("kill");
        exit(1);
    }

    //give handler a moment to run before we exit
    sleep(1);

    printf("main: exiting normally\n");
    return 0;
}

//output:
// process pid = 14530
// raising SIGUSR1 to self...
// my_handler: caught user-defined signal 10
// main: exiting normally