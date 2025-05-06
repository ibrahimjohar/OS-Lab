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

        if(WIFEXITED(wstat))
        {
            fprintf(stdout, "child with PID %d exited w/ status %d\n", pid, WEXITSTATUS(wstat));
        }
        else
        {
            fprintf(stdout, "child with PID %d exited abnormally\n", pid);
        }

        // fprintf(stdout, " return code: %d\n", WEXITSTATUS(wstat));
    }
}

int main()
{
    // when a child terminates, 
    // this function will be automatically triggered by the kernel.
    signal(SIGCHLD, proc_exit);


    for(int i = 0; i < 3; i++)
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }
        else if(pid == 0)
        {
            //child process
            printf("child %d: alive and will now exit\n", i+1);
            exit(i+1);
        }
        //parent continues loop 
    }

    //let children terminate & become zombies briefly
    printf("parent sleeping...\n");
    sleep(5);

    printf("parent: finished sleeping, now exiting\n");
    return 0;

    // switch(fork()) //forks a new child process
    // {
    //     case -1:
    //         perror("main: fork");
    //         exit(0);
    //     case 0:
    //         printf("im alive (temporarily)\n"); //child only executes this and exits
    //         int ret_code = rand();

    //         printf("return code is %d\n", ret_code);
    //         exit(ret_code); //As soon as child exits, the OS sends SIGCHLD to the parent process.
    //     default:
    //         pause();    //suspends main process execution until a signal arrives
    // }
    // exit(0);
}

//output:
// child 1: alive and will now exit
// child 2: alive and will now exit
// parent sleeping...
// child with PID 17094 exited w/ status 1
// child with PID 17095 exited w/ status 2
//  return value of wait3() is 0
// parent: finished sleeping, now exiting
// child 3: alive and will now exit