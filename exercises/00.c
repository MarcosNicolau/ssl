#include <stdlib.h>
#include <stdio.h>

int getStringSize(char *string)
{
    int size = 0;
    // Get the length of the string
    while (string[size])
        size++;
    return size;
}

char *concatenateStrings(char *string_1, char *string_2)
{
    // Before pushing, ensure there is memory for the concatenated string
    char *string = malloc(sizeof(string_1) + sizeof(string_2));
    int counter_1 = 0;
    int counter_2 = 0;
    int string_counter = 0;
    while (string_1[counter_1])
    {
        string[string_counter] = string_1[counter_1];
        string_counter++;
        counter_1++;
    };
    while (string_2[counter_2])
    {
        string[string_counter] = string_2[counter_2];
        string_counter++;
        counter_2++;
    };

    return string;
}

int isPrefix(char *string_1, char *string_2)
{
    // We assume that the string_2 is a prefix, we then verify our assumption by checking if one of the words of the string_2 at x pos does not match string_1 at the same pos
    int isPrefix = 1;
    int counter = 0;
    while (string_2[counter])
    {
        if (string_1[counter] != string_2[counter])
        {
            isPrefix = 0;
            break;
        }
        counter++;
    }
    return isPrefix;
}

int main(int argc, char *argv[])
{
    // If it does not receive a string, then we take it as empty
    if (argc == 1)
    {
        printf("The string is empty");
        return 0;
    };

    printf("The size of the string is %d", getStringSize(argv[1]));
    // If the client provided another argument, we run the other fns
    if (argc != 3)
        return 0;
    printf("\nThe concatenated string is %s", concatenateStrings(argv[1], argv[2]));
    printf("\nIt is%s a prefix", isPrefix(argv[1], argv[2]) ? "" : " not");
    return 0;
}