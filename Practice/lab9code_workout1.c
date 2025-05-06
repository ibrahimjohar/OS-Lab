// A C program that demonstrates the use of a signal handler for the SIGINT signal 
// (which is sent when the user presses CTRL+C).
// The program will print a message when the signal is received.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//signal handler function
void sigint_handler(int signum)
{
    fprintf(stdout, " -> caught SIGINT signal (%d)\n", signum);
    raise(SIGKILL);
}

int main()
{
    //registering signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        printf("error setting up signal handler for SIGINT\n");
        return 1;
    }

    printf("press ctrl+c to send a SIGINT signal\n");

    //infinite loop to keep program running
    while(1){
        sleep(1);
    }

    return 0;
}

//output:
// press ctrl+c to send a SIGINT signal
// ^C -> caught SIGINT signal (2)
// Killed
