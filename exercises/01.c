#include <stdio.h>
#define COLS cols
// This allows to dynamically change the value of cols.
int cols;
#include "../libs/languages.h"
#include "../libs/input.h"

int alphabet(char letter)
{
    if (letter == '+' || letter == '-' || (letter >= '0' && letter <= '9'))
        return 1;
    return 0;
}

int get_col(char c)
{
    switch (c)
    {
    case '-':
        return 0;
    case '+':
        return 1;
    default:
        return (c >= '0' && c <= '9') ? 2 : 3;
    };
}

int main(int argc, char *argv[])
{
    char *string = getArgument(argc, argv);
    int stateMatrix[4][3] = {{1, 1, 2},
                             {3, 3, 2},
                             {3, 3, 2},
                             {3, 3, 3}};
    if (!isAlphabetString(string, alphabet))
    {
        printf("%s does not belong to the alphabet \n", string);
    }
    COLS = 3;
    if (!isLanguageWord_1(string, stateMatrix, get_col))
    {
        printf("%s is not a string of the language \n", string);
    }
    else
        printf("%s is a string of the language \n", string);
    return 0;
}