#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED
#include "./consts.h"

int isAlphabetString(char *word, int isAlphabetCharacter(char word))
{
    for (int i = 0; word[i]; i++)
    {
        if (!isAlphabetCharacter(word[i]))
            return 0;
    };
    return 1;
}

/**
 * @param string the string to validate
 * @param alphabet a function that returns 1 if the a character belongs to the alphabet and 0 if not
 * @param transition_matrix the automata transition matrix
 * @param get_col a function that given returns the columns of the transition matrix
 * @param final_states_size the size of the array of final state
 * @param final_states an array composed of the possible final states
 * @param on_state_change a function that runs after every transition. If you don't want to run anything pass NULL
 *
 * @returns an error message, if there is any, indicating the type of error, otherwise, returns empty string
 */
char *automata_validation(char *string, int (*alphabet)(char c), int cols, int transition_matrix[][cols], int (*get_col)(char), int final_states_size, int final_states[final_states_size], void (*on_state_change)(int state, int prev_state, int col, char c))
{
    int i = 0;
    int state = 0;
    char c = string[i];
    int prev_state = state;
    int col = 0;

    while (c != '\0')
    {
        int belongs_to_alphabet = alphabet(c);
        if (!belongs_to_alphabet)
            return ERROR_MSG.NOT_ALPHABET_STRING;

        col = get_col(c);
        prev_state = state;
        state = transition_matrix[state][col];

        if (on_state_change != NULL)
            on_state_change(state, prev_state, col, c);

        c = string[++i];
    };
    // We have to run the fn one more time for the last word
    if (on_state_change != NULL)
        on_state_change(state, prev_state, col, c);
    // Finally, check whether the final state is valid
    for (int i = 0; i < final_states_size; i++)
    {
        if (state == final_states[i])
            return '\0';
    }

    return ERROR_MSG.LEXICAL_ERROR;
}

#endif
