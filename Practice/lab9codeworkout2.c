// When a child process stops or terminates, SIGCHLD is sent to the parent process. The default response to the signal is
// to ignore it. The signal can be caught and the exit status from the child process can be obtained by immediately calling
// wait (2) and wait3 (3C). This allows zombie process entries to be removed as quickly as possible. The following
// example demonstrates installing a handler that catches SIGCHLD. The wait3() system call uses WNOHANG
// parameter to return immediately if no child process has terminated.

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>

void proc_exit()
{
    int wstat;
    pid_t pid;

    while(1){
        //get info about child process
        //WNOHANG returns immediately if there is no child to wait
        // /NOHANG ensures the parent doesn’t get stuck if no child has exited yet
        pid = wait3(&wstat, WNOHANG, NULL);

        if (pid == 0 || pid == -1)
        {
            fprintf(stdout, " return value of wait3() is %d\n", pid);
            return;
        }
        fprintf(stdout, " return code: %d\n", WEXITSTATUS(wstat));
    }
}

int main()
{
    // when a child terminates, 
    // this function will be automatically triggered by the kernel.
    signal(SIGCHLD, proc_exit);

    switch(fork()) //forks a new child process
    {
        case -1:
            perror("main: fork");
            exit(0);
        case 0:
            printf("im alive (temporarily)\n"); //child only executes this and exits
            int ret_code = rand();

            printf("return code is %d\n", ret_code);
            exit(ret_code); //As soon as child exits, the OS sends SIGCHLD to the parent process.
        default:
            pause();    //suspends main process execution until a signal arrives
    }
    exit(0);
}

// Why Do We Do This?

//     Avoid zombie processes
//     When a child terminates, it becomes a zombie until the parent calls wait(), waitpid(), or wait3() to reap it.

//     Handle child status proactively
//     Catching SIGCHLD lets the parent clean up immediately.

//     Non-blocking wait
//     WNOHANG ensures the parent doesn’t get stuck if no child has exited yet.

//output:
// im alive (temporarily)
// return code is 1804289383
//  return code: 103
//  return value of wait3() is -1