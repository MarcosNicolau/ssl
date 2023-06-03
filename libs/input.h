#include <stdio.h>
#include <stdlib.h>

char *getArgument(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("An argument must be provided. Exiting program...");
        exit(-1);
    };
    return argv[1];
}