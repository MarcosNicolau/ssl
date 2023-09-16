#ifndef EVAL_H_INCLUDED
#define EVAL_H_INCLUDED

int char_to_int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return 0;
};

int power(int number, unsigned int x)
{
    int result = number;
    if (x == 0)
        return 1;
    for (int i = 1; i < x; i++)
    {
        result = result * number;
    }
    return result;
}

int calculate(int number1, char operation, int number2)
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
    case '^':
        return power(number1, number2);
    default:
        return number2;
    };
};

int mergeNumbers(int number1, int number2)
{
    return (number1 * 10 + number2);
}

#endif