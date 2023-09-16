#include <stdio.h>
#include "./libs/os.h"
#include "./libs/calculator.h"
#include "./libs/validation.h"
#include "./libs/consts.h"
#include "./libs/lists.h"

int get_col(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '^')
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

/**
 * Resolves the list in order, that is it does not respect the precedence of the operators.
 *
 * @param list expects a list where every number is followed by an operation(+,-,/,-,^) which has to be followed by another number.
 */
int resolve_list(Node *list)
{
    int result = list->value;
    while (list->next != NULL)
    {
        char operation = list->next->value;
        Node *number2Ptr = list->next->next;
        result = calculate(result, operation, number2Ptr->value);
        if (number2Ptr->next != NULL)
            list = number2Ptr;
        else
            break;
    }
    return result;
}

int eval(char *string)
{
    Node *result_queue = NULL;
    Node *precedence_queue = NULL;
    int i = 0;
    int number = 0;
    char c = string[i];

    while (c != '\0')
    {
        int col = get_col(c);
        if (col == 1)
        {
            push_back(number, &precedence_queue);
            push_back(resolve_list(precedence_queue), &result_queue);
            push_back(c, &result_queue);
            precedence_queue = NULL;
            number = 0;
        }
        else if (col == 2)
        {
            push_back(number, &precedence_queue);
            push_back(c, &precedence_queue);
            number = 0;
        }
        else
            number = mergeNumbers(number, char_to_int(c));

        c = string[++i];
    }

    push_back(number, &precedence_queue);
    push_back(resolve_list(precedence_queue), &result_queue);

    return resolve_list(result_queue);
}

int main(int argc, char *argv[])
{
    char *string = getSingleArgument(argc, argv);
    // Check the automata here file://./assets/automata_2.png
    int transition_matrix[4][3] = {
        {1, 2, 3},
        {1, 2, 2},
        {1, 3, 3},
        {3, 3, 3}};
    int final_states[1] = {1};

    int is_valid1 = is_alphabet_string(string, alphabet);
    if (!is_valid1)
    {
        printf("%s", ERROR_MSG.NOT_ALPHABET_STRING);
        return -1;
    }
    int is_valid = automata_validation(string, 3, transition_matrix, get_col, 1, final_states);
    if (!is_valid)
    {
        printf("%s", ERROR_MSG.LEXICAL_ERROR);
        return -1;
    }
    int result = eval(string);
    printf("The result of the operation is: %d\n", result);
    return 0;
}