#ifndef EVAL_H_INCLUDED
#define EVAL_H_INCLUDED

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

#endif