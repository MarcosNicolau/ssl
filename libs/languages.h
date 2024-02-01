// Note that for this to work, the COLS macro must be defined. like so: #define COLS cols
// COLS represents the number of columns of the Automata, which are the number of characters in the alphabet.
// In order to the algorithms to work, the err state must be the number of COLS
#ifndef LANGUAGES_H_INCLUDED
#define LANGUAGES_H_INCLUDED

#include <stdio.h>

int isAlphabetString(char *word, int isAlphabetCharacter(char word))
{
    for (int i = 0; word[i]; i++)
    {
        if (!isAlphabetCharacter(word[i]))
            return 0;
    };
    return 1;
}

// Algorithm 1: checks whether the state has fallen on the failure state(number of rows) on every entry
int isLanguageWord_1(char *word, int rows, int cols, int state_matrix[][cols], int get_col(char c), int number_of_final_states, int final_states[number_of_final_states])
{
    int i = 0;
    int state = 0;
    char c = word[i];

    while (c != '\0')
    {
        state = state_matrix[state][get_col(c)];
        if (state == rows)
            return 0;
        c = word[++i];
    }
    for (int i = 0; i < number_of_final_states; i++)
    {
        if (state == final_states[i])
            return 1;
    }
    return 1;
}

// Algorithm 2: Loop through the whole word and then check whether it can end in that state or not.
int isLanguageWord_2(char *word, int cols, int state_matrix[][cols], int get_col(char c), int number_of_final_states, int final_states[number_of_final_states])
{
    int i = 0;
    int state;
    char c = word[i];

    while (c != '\0')
    {
        state = state_matrix[state][get_col(c)];
        c = word[++i];
    }
    for (int i = 0; i < number_of_final_states; i++)
    {
        if (state == final_states[i])
            return 1;
    }
    return 0;
}

/**
 * @param cb a function that runs after every word, and receives the state, If you don't want to run anything pass NULL
 */
int automataValidationWithSeparator(char *word, char separator, int rows, int cols, int transitionMatrix[rows][cols], int (*get_col)(char), void (*onValidWord)(int state, int isLastWord), void (*onFailureState)(int failureState))
{
    int i = 0;
    int state = 0;
    char c = word[i];

    while (c != '\0')
    {
        if (c != separator)
        {
            state = transitionMatrix[state][get_col(c)];
            if (state == rows)
            {
                onFailureState(rows);
            }
        }
        else
        {
            if (onValidWord != NULL)
                onValidWord(state, 0);
            state = 0;
        }
        c = word[++i];
    };
    if (onValidWord != NULL)
        onValidWord(state, 1);
}

#endif
