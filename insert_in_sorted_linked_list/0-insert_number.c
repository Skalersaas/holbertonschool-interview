#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
listint_t* insert_node(listint_t** head, const int n)
{
    listint_t* new;
    listint_t* current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        listint_t* prev;
        prev = malloc(sizeof(listint_t));
        while (1) {
            if(current->next == NULL)
            {
                current->next= new;
                break;
            }
            else if (current->n < n)
            {
                prev = current;
                current = current->next;
            }
            else if(prev->next == NULL)
            {
                new->next = *head;
                *head = new;
                break;
            }
            else
            {
                prev->next = new;
                new->next = current;
                break;
            }
        }
    }

    return (new);
}
