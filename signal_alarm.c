/**
 * File: signal_alarm.c
 * Modified by: Alex Toma
 * 
 * Brief summary of program: this program sets a 5 second alarm and waits in an
 * infinite loop. Once the alarm signal is recieved, it handles it and exits
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// signal handler function
void alarm_handler() 
{
    printf("Alarm signal received...\n");
    exit(1);
}

int main() 
{
    // register the handler for the signal
    signal(SIGALRM, alarm_handler);

    // set a 5 second alarm
    alarm(5);

    // keep program running until the alarm triggers
    int i = 0;

    while(1) 
    {
        // makes sure the loop isn't empty so program runs
        i++; 
    }
    
    return i;
}
