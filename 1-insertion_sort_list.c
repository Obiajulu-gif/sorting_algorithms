#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;


current = (*list)->next;

while (current != NULL)
{
temp = current;
prev = current->prev;

while (prev != NULL && temp->n < prev->n)
{
prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = prev;

temp->next = prev;
temp->prev = prev->prev;

if (prev->prev != NULL)
prev->prev->next = temp;
else
*list = temp;

prev->prev = temp;

print_list(*list);
prev = temp->prev;
}

current = current->next;
}
}
