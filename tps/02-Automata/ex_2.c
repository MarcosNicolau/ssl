#include <stdio.h>
#include "./libs/os.h"
#include "./libs/eval.h"

int main(int argc, char *argv[])
{
    char *string = getSingleArgument(argc, argv);
    int result = eval(string);
    printf("The result of the operation is: %d\n", result);

    return 0;
}