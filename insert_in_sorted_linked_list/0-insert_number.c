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

            if (current->n < n && current->next != NULL)
            {
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
int main() {
    listint_t* head;
    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);

    printf("-----------------\n");

    insert_node(&head, 27);
    insert_node(&head, 272);
    insert_node(&head, 17);

    print_listint(head);

    free_listint(head);

    return (0);
}