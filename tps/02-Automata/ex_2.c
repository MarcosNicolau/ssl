#include <stdio.h>
#include "./libs/os.h"
#include "./libs/calculator.h"
#include "./libs/automata.h"

int get_col(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    else
        return -1;
}

int alphabet(char c)
{
    if (get_col(c) != -1)
        return 1;
    return 0;
}

// Not a fan of global variables but I can't find any workaround
int result = 0;
void calculate_result(int, int, int col, char c)
{
    // Declaring this variables as static so they don't lose their state between each call
    // This is pretty useful, because it allows us to limit the scope of the variables
    static int tmp_res = 0;
    static char tmp_operation = '\0';
    static char operation = '\0';

    if (col == 1 || c == '\0')
    {
        result = calculate(result, tmp_res, operation);
        operation = c;
        tmp_res = 0;
        tmp_operation = '\0';
    }
    if (col == 2)
    {
        tmp_operation = c;
    }
    else
    {
        tmp_res = calculate(tmp_res, char_to_int(c), tmp_operation);
    }
}

int main(int argc, char *argv[])
{
    char *string = getSingleArgument(argc, argv);
    // Check the automata here file://./../assets/automata_2.png
    int transition_matrix[4][3] = {
        {1, 2, 3},
        {3, 2, 2},
        {1, 3, 3},
        {3, 3, 3}};
    int final_states[1] = {1};

    char *error_msg = automata_validation(string, alphabet, 3, transition_matrix, get_col, 1, final_states, calculate_result);
    if (!error_msg)
    {
        printf("The result of the operation is: %d\n", result);
        return 0;
    }
    printf("%s", error_msg);
    return -1;
}