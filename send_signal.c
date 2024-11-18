/**
 * File: send_signal.c
 * Modified by: Alex Toma
 * Assignment: Lab 10: Signals
 * Class Section: 121
 * Brief summary of program: this program sends a SIGUSR1 signal with a random int value 
 * to a specified pid using the sigqueue function
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    union sigval signal_value;
    int target_pid;

    // get pid of current running process
    printf("Enter the target pid:\n");
    scanf("%d", &target_pid);

    // get random seed
    srand(time(NULL));

    // set sigval to a random int
    signal_value.sival_int = rand();

    // send a SIGUSR1 signal with the random int to the pid
    if (sigqueue(target_pid, SIGUSR1, signal_value) == -1) 
    {
        perror("ERROR: Failed to send signal using sigqueue");
        exit(1);
    }

    printf("SIGUSR1 signal sent to PID %d with value: %d\n", target_pid, signal_value.sival_int);
    return 0;
}
