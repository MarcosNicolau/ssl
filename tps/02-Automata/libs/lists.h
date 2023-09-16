#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int is_empty(Node *node)
{
    return !node;
}

void push_front(int value, Node **node)
{
    Node *new_node = (Node *)
        malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *node;
    *node = new_node;
}

void push_back(int value, Node **node)
{
    Node *new_node = (Node *)
        malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    if (*node == NULL)
    {
        *node = new_node;
        return;
    }
    Node *tmp = *node;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    };
    tmp->next = new_node;
}

int pop(Node **node)
{
    if (is_empty(*node))
        return -1;
    int popped = (*node)->value;
    Node *tmp = *node;
    *node = tmp->next;
    free(tmp);
    return popped;
}

void show(Node *list)
{
    while (list->next != NULL)
    {
        printf("%d\n", list->value);
        list = list->next;
    }
    printf("%d\n", list->value);
}

#endif