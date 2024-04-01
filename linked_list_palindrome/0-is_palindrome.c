#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int list_size(listint_t* h)
{
    listint_t* current;
    unsigned int n;

    current = h;
    n = 0;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }

    return (n);
}

listint_t* get(listint_t* head, int num)
{
    listint_t* current;

    current = head;
    while (current != NULL && num != 0)
    {
        current = current->next;
        num--;
    }
    return current;
}
int is_palindrome(listint_t** head)
{
    int size = list_size(*head) / 2;
    listint_t* center = get(*head, size);

    int i;
    int even;

    even = size % 2;;
    for (i = 0; i < size;i++)
        if (get(*head, size - i - even)->n != get(center, i)->n)
            return 0;
    return 1;
}
