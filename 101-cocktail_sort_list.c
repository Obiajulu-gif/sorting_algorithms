#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a linked list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 * @head: The head of the linked list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **head)
{
if (node1 == NULL || node2 == NULL || head == NULL || *head == NULL)
return;

if (node1->prev != NULL)
node1->prev->next = node2;
else
*head = node2;

if (node2->next != NULL)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;
node1->prev = node2;
node2->next = node1;
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
*                      in ascending order using the cocktail sort algorithm
* @list: The doubly linked list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current, *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
do {
swapped = 0;
current = *list;
while (current->next != NULL)
{
if (current->n > current->next->n)
{
swap_nodes(current, current->next, list);
swapped = 1;
print_list(*list);
}
else
{
current = current->next;
}
}

if (swapped == 0)
break;

temp = current;
while (temp->prev != NULL)
{
if (temp->n < temp->prev->n)
{
swap_nodes(temp->prev, temp, list);
swapped = 1;
print_list(*list);
}
else
{
temp = temp->prev;
}
}
} while (swapped);
}
