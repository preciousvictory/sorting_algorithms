#include "sort.h"

/**
 * sinsertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: Doubly linked list node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = node->next)
	{
		for (next = node->next; next != NULL; next = next->next)
		{
			if (node->n > next->n)
			{
				swap(node, next, list);
				print_list(*list);
			}
		}
	}
}

/**
 * swap - swap two nodes
 * @node: current node
 * @next: next node
 * @list: double linked list
 */
void swap(listint_t *node, listint_t *next, listint_t **list)
{
	listint_t *back = node->prev, *new = next->next;

	if (back)
		back->next = next;
	else
		*list = next;

	node->prev = next;
	node->next = new;
	next->prev = back;
	next->next = node;

	if (new)
		new->prev = node;
}
