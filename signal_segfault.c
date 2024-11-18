/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Alex Toma
 * Assignment: Lab 10: Signals
 * Class Section: 121
 * Brief summary of modifications: added a segfault handler function and a signal into main
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void segfault_handler()
{
    printf("Segmentaion fault recieved\n");
}

int main (int argc, char* argv[]) {
    
    // signal register
    signal(SIGSEGV, segfault_handler);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}