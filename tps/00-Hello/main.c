#include <stdio.h>

int main(int argc,  char *argv[]) {
   //The program name is always passed as the first argument
    printf("Program name: %s\n", argv[0]);

    printf("\nPrinting all the provided arguments: \n");
    //Creating counter here so we can check later if any arguments were provided
    //Also, note that the variable is initialized to 1, that is because the index 0 of argv is the program name.
    int i = 1;
    for (; i < argc; i++) {
      argv[i] && printf("\t- The argument number %d supplied is: \"%s\"\n", i, argv[i]);
    }

    // If the counter hasn't incremented, then it means that no arguments were provided
    if(i == 1) printf("No arguments provided");

    return 0;
}