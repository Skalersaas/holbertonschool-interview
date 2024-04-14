#include "lists.h"
#include <stdio.h>

int check_cycle(listint_t* list)
{
    if (list == list->next)
        return (1);
    const listint_t* current;

    current = list;
    while (current != NULL)
    {
        if (check_node(list, current) == 1)
            return (1);
        current = current->next;
    }
    return (0);
}

int check_node(listint_t* list, listint_t* node)
{
    const listint_t* current;

    current = list;
    while (current != node)
    {
        if (current == node->next)
            return (1);
        current = current->next;
    }
    return (0);
}
