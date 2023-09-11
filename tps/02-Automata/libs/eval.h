#ifndef EVAL_H_INCLUDED
#define EVAL_H_INCLUDED

#include "./lists.h"
#include "./automata.h"

int char_to_int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return 0;
};

int calculate(int number1, int number2, char operation)
{
    switch (operation)
    {
    case '+':
        return number1 + number2;
    case '-':
        return number1 - number2;
    case '*':
        return number1 * number2;
    case '/':
        return number1 / number2;
    default:
        return number2;
    };
};

int calculate_list(struct CharNode *stack)
{
    int value = char_to_int(stack->value);
    while (stack->next != NULL)
    {
        // If there is a next value then the following must be an operation and the following of that one, must be another number
        // That, of course, supposing that the string was previously validated using its respective automata
        value = calculate(value, char_to_int(stack->next->next->value), stack->next->value);
        stack = stack->next->next;
    }
    return value;
}

int eval_get_col(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
}

int get_result(char *string)
{
    struct CharNode *queue = NULL;
    int i = 0;
    char c = string[i];
    int result = 0;
    char operation = '\0';

    while (1)
    {
        if (eval_get_col(c) == 1 || c == '\0')
        {
            result = calculate(result, calculate_list(queue), operation);
            operation = c;
            free(queue);
            queue = NULL;
        }
        else
        {
            push_back(c, &queue);
        }
        if (c == '\0')
            break;
        c = string[++i];
    }

    return result;
}

int eval(char *string)
{
    // Check the automata here file://./../assets/automata_2.png
    int eval_transition_matrix[4][3] = {
        {1, 2, 3},
        {3, 2, 2},
        {1, 3, 3},
        {3, 3, 3}};
    int final_states[1] = {1};
    int valid = automata_validation(string, -1, 3, eval_transition_matrix, eval_get_col, 1, final_states, NULL);
    if (!valid)
    {
        printf("There has been a lexical word! Exiting program...");
        exit(-1);
    }
    return get_result(string);
}

#endif