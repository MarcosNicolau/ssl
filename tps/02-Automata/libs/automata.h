#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

/**
 * @param on_separator a function that runs whenever the automata recognizes a separator. It receives the state before the separator. If you don't want to run anything pass NULL
 *
 * @returns 1 if its valid, otherwise 0
 */
int automata_validation(char *word, int separator_col, int cols, int transition_matrix[][cols], int (*get_col)(char), int final_states_size, int final_states[final_states_size], void (*on_separator)(int state))
{
    int i = 0;
    int state = 0;
    int prev_state;
    char c = word[i];

    while (c != '\0')
    {
        prev_state = state;
        int col = get_col(c);
        state = transition_matrix[state][col];
        if (col == separator_col)
        {
            if (on_separator != NULL)
                on_separator(prev_state);
        }
        c = word[++i];
    };
    // We have to run on_separator one more time for the last word
    if (on_separator != NULL)
        on_separator(state);

    // Finally, check whether the final state is valid
    for (int i = 0; i < final_states_size; i++)
    {
        if (state == final_states[i])
            return 1;
    }

    return 0;
}

#endif
