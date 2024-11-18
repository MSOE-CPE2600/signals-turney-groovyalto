/**
 * File: 
 * Modified by: Alex Toma
 * Assignment: Lab 10: Signals
 * Class Section: 121
 * Brief summary of program: this program forks, then uses a child to pass the SIGUSR1 
 * signal to the parent. This signal is then caught by the created handler method
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

// signal handler function for SIGUSR1
void signal_handler(int signo, siginfo_t *info, void *context)
{
    printf("Recieved SIGUSR1 pid: %d\n", info->si_pid);
}

int main()
{
    pid_t pid = fork();

    // emergency test case for fork error
    if(pid == -1)
    {
        perror("ERROR: Failed to fork");
        exit(1);
    }

    if(pid == 0)
    {
        // create child
        kill(getppid(), SIGUSR1);
        printf("Child signal sent");
    } else 
    {
        // make struct for parent process
        struct sigaction action;
        
        //set struct to custom handler
        action.sa_sigaction = signal_handler;
        
        // set flag for the data to save to extended signal info
        action.sa_flags = SA_SIGINFO;
        
        // register the handler for SIGUSR1
        sigaction(SIGUSR1, &action, NULL);

        // wait for the child process to send the signal
        printf("Parent waiting for SIGUSR1 from child\n");
        wait(NULL);
        printf("Parent: Child has terminated\n");
    }

    return 0;
}
