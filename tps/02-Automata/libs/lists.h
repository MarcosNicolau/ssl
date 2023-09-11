#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct CharNode
{
    char value;
    struct CharNode *next;
};

int is_empty(struct CharNode *node)
{
    return !node;
}

void push_front(char value, struct CharNode **node)
{
    struct CharNode *new_node = (struct CharNode *)
        malloc(sizeof(struct CharNode));
    new_node->value = value;
    new_node->next = *node;
    *node = new_node;
}

void push_back(char value, struct CharNode **node)
{
    struct CharNode *new_node = (struct CharNode *)
        malloc(sizeof(struct CharNode));
    new_node->value = value;
    new_node->next = NULL;
    if (*node == NULL)
    {
        *node = new_node;
        return;
    }
    struct CharNode *tmp = *node;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    };
    tmp->next = new_node;
}

char pop(struct CharNode **node)
{
    if (is_empty(*node))
        return -1;
    char popped = (*node)->value;
    struct CharNode *tmp = *node;
    *node = tmp->next;
    free(tmp);
    return popped;
}

#endif