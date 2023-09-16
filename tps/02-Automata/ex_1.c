#include <stdio.h>
#include "./libs/os.h"
#include "./libs/validation.h"
#include "./libs/consts.h"

int get_col(char c)
{
    if (c == '0')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c >= '0' && c <= '7')
        return 2;
    if (c >= '8' && c <= '9')
        return 3;
    if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        return 4;
    if (c == 'X' || c == 'x')
        return 5;
    if (c == '$')
        return 6;
    else
        return -1;
}

int alphabet(char c)
{
    if (get_col(c) != -1)
        return 1;
    return 0;
}

typedef struct Counter
{
    int octal;
    int decimal;
    int hex;
} Counter;

enum NUMBER_TYPES
{
    DECIMAL,
    OCTAL,
    HEX
};

enum NUMBER_TYPES get_type_of_number(char *string)
{
    char first = string[0];
    char second = string[1];
    if (first == '0' && (second == 'x' || second == 'X'))
        return HEX;
    if (first == '0' && second >= '0' && second <= '7')
        return OCTAL;
    return DECIMAL;
};

Counter count(char *string)
{
    Counter counter = {0, 0, 0};
    int i = 0;
    char c = string[i];
    while (c != '\0')
    {
        if (c == '$' || i == 0)
        {
            char str[2];
            str[0] = string[i == 0 ? i : i + 1];
            str[1] = string[i == 0 ? i + 1 : i + 2];
            enum NUMBER_TYPES typeof_number = get_type_of_number(str);
            if (typeof_number == DECIMAL)
                counter.decimal++;
            if (typeof_number == OCTAL)
                counter.octal++;
            if (typeof_number == HEX)
                counter.hex++;
        }

        c = string[++i];
    }

    return counter;
}

int main(int argc, char *argv[])
{
    char *string = getSingleArgument(argc, argv);
    /**
     * This transition matrix has 10 states where the columns are
     * 0 [+-] [1-7] [8-9] [A-Fa-f] [Xx] [$]
     * and the 10th row is the failure state
     *
     * This automata recognizes:
     * -  Decimal numbers: can be a single zero or a sequence of one or more decimal digits that starts with a non-zero decimal digit. The decimal digits are 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.
     * -  Octal numbers: starts with a zero and is followed by a single zero or a non-empty sequence of octal digits that starts with a non-zero octal digit. An octal digit is one of 0, 1, 2, 3, 4, 5, 6 or 7.
     * -  Hexadecimal numbers: starts with a zero and is followed by an upper or lower case "x", and either a single zero or a non-zero hexadecimal digit and a sequence of zero or more hexadecimal digits. Hexadecimal digits include the decimal digits and the letters a, b, c, d, e and f and their uppercase versions.
     *
     * You can check the automata here: file://./assets/automata_1.png
     */
    int transition_matrix[10][7] = {
        {3, 1, 2, 2, 9, 9, 9},  // state 0
        {3, 9, 2, 2, 9, 9, 0},  // state 1
        {2, 9, 2, 2, 9, 9, 0},  // state 2 DECIMAL
        {4, 9, 5, 9, 9, 6, 0},  // state 3 DECIMAL
        {9, 9, 9, 9, 9, 9, 0},  // state 4 OCTAL
        {5, 9, 5, 9, 9, 9, 0},  // state 5 OCTAL
        {7, 9, 8, 8, 8, 9, 9},  // state 6
        {9, 9, 9, 9, 9, 9, 0},  // state 7 HEXA
        {8, 9, 8, 8, 8, 9, 0},  // state 8 HEXA
        {9, 9, 9, 9, 9, 9, 9}}; // state 9 failure
    int final_states[6] = {2, 3, 4, 5, 7, 8};
    int alphabet_string = is_alphabet_string(string, alphabet);
    if (!alphabet_string)
    {
        printf("%s", ERROR_MSG.NOT_ALPHABET_STRING);
        return -1;
    }
    int is_valid = automata_validation(string, 7, transition_matrix, get_col, 6, final_states);
    if (!is_valid)
    {
        printf("%s", ERROR_MSG.LEXICAL_ERROR);
        return -1;
    }
    Counter counter = count(string);
    printf("Count: \ndecimal: %d \noctal: %d\nhexa: %d\n", counter.decimal, counter.octal, counter.hex);
    return 0;
}