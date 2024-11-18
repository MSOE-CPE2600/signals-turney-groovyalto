/**
 * File: recv_signal.c
 * Modified by: Alex Toma
 * Assignment: Lab 10: Signals
 * Class Section: 121 
 * Brief summary of program: this program waits for a SIGUSR1 signal using a sigaction 
 * handler and prints the value passed with the signal before exiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


// signal handler function
void signal_handler(int signo, siginfo_t *info, void *context) 
{
    // display the int value sent
    printf("Received signal with value: %d\n", info->si_value.sival_int);
    exit(1);
}

int main() 
{
    // create a struct to setup signal handler
    struct sigaction action;

    // set struct to handler
    action.sa_sigaction = signal_handler;  

    // set flag to save data
    action.sa_flags = SA_SIGINFO;          

    // register for the signal
    if (sigaction(SIGUSR1, &action, NULL) == -1) 
    {
        perror("Error setting up signal handler");
        exit(1);
    }

    // give instructions to user
    printf("Run 'ps' after pressing Ctrl + Z to find the pid\n");

    // keep the program running indefinitely to wait for signals
    while (1) 
    return 0;
}