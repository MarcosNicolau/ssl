#include <stdio.h>
#include <stdlib.h>

/**
 * Calling this fn makes argument mandatory to run the program.
 * If an argument is not provided, then the program exits
 */
char *getSingleArgument(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("An argument must be provided. Exiting program...");
        exit(-1);
    };
    return argv[1];
}
