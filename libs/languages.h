// Note that for this to work, the COLS macro must be defined.
// COLS represents the number of columns of the Automata, which are the number of characters in the alphabet.
#ifdef COLS
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

// Algorithm 1: checks whether the state is correct on every entry
int isLanguageWord_1(char *word, int stateMatrix[][COLS], int get_col(char c))
{
    int i = 0;
    int state = 0;
    char c = word[i];

    while (c != '\0')
    {
        state = stateMatrix[state][get_col(c)];
        if (state == COLS)
            return 0;
        c = word[++i];
    }
    return 1;
}

// Algorithm 2: Loop through the whole word and then check whether the state is correct or not.
int isLanguageWord_2(char *word, int stateMatrix[][COLS], int get_col(char c))
{
    int i = 0;
    int state;
    char c = word[i];

    while (c != '\0')
    {
        state = stateMatrix[state][get_col(c)];
        c = word[++i];
    }

    if (state == COLS)
        return 0;

    return 1;
}

#endif
#endif