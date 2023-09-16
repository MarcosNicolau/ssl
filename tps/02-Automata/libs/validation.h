#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

int is_alphabet_string(char *word, int isAlphabetCharacter(char word))
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
 * @param transition_matrix the automata transition matrix
 * @param get_col a function that given returns the columns of the transition matrix
 * @param final_states_size the size of the array of final state
 * @param final_states an array composed of the possible final states
 *
 * @returns 1 if valid, otherwise 0
 */
int automata_validation(char *string, int cols, int transition_matrix[][cols], int (*get_col)(char), int final_states_size, int final_states[final_states_size])
{
    int i = 0;
    int state = 0;
    char c = string[i];
    int prev_state = state;
    int col = 0;

    while (c != '\0')
    {
        col = get_col(c);
        prev_state = state;
        state = transition_matrix[state][col];

        c = string[++i];
    };

    // Finally, check whether the final state is valid
    for (int i = 0; i < final_states_size; i++)
    {
        if (state == final_states[i])
            return 1;
    }

    return 0;
}

#endif
