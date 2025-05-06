// Same requirements as of Code workout # 1, however using the sigaction() system call this is used now-a-days in all
// production code instead of signal() system call.

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//signal handler function
void sigint_handler(int signum)
{
    printf("ctrl+c (SIGINT) received. exiting...\n");
    //perform cleanup or other necessary tasks before exiting
    exit(signum);
}

int main()
{
    //set up the signal action structure
    struct sigaction sa;    //structure lets you define how your program will respond to a specific signal.

    sa.sa_handler = sigint_handler;     //specify the signal handler function
    
    //Clears all signals from the signal mask, 
    //i.e.,no other signals will be blocked during execution of the handler.
    //"don't block any other signals while sigint_handler() is running."
    sigemptyset(&sa.sa_mask);     //clear the signal mask
    
    
    //no special behavior is requested.
    //could set flags like SA_RESTART here
    sa.sa_flags = 0;

    //register the signal handler for SIGINT using sigaction
    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    //loop indefinitely to keep the program running
    while(1)
    {

    }

    return EXIT_SUCCESS;
}