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

    if (*head == NULL || current->n > n)
    {
        new->next = current;
        *head = new;
    }
    else
    {
        listint_t* prev;
        prev = malloc(sizeof(listint_t));
        while (1) 
        {
            if (current->n < n)
            {
                if(current->next==NULL)
                {
                    current->next = new;
                    break;
                }
                prev = current;
                current = current->next;
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
