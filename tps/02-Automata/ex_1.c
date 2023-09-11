#include <stdio.h>
#include "./libs/os.h"
#include "./libs/automata.h"

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
}

int octal_count = 0;
int decimal_count = 0;
int hex_count = 0;

void count(int state)
{
    if (state == 1 || state == 2 || state == 3)
        decimal_count++;
    else if (state == 4 || state == 5)
        octal_count++;
    else
        hex_count++;
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
        {7, 9, 8, 8, 8, 9, 9},  // state 6 HEXA
        {9, 9, 9, 9, 9, 9, 0},  // state 7 HEXA
        {8, 9, 8, 8, 8, 9, 0},  // state 8 HEXA
        {9, 9, 9, 9, 9, 9, 0}}; // state 9 failure
    int separator_col = get_col('$');
    int final_states[6] = {2, 3, 4, 5, 7, 8};
    int is_valid = automata_validation(string, separator_col, 7, transition_matrix, get_col, 6, final_states, count);

    if (!is_valid)
    {
        printf("There has been a lexical word! Exiting program...");
        return -1;
    }
    printf("Count: \ndecimal: %d \noctal: %d\nhexa: %d", decimal_count, octal_count, hex_count);

    return 0;
}