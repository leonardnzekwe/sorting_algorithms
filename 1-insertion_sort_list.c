#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * Of integers in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *fwd, *current, *previous;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (fwd = (*list)->next; fwd != NULL; fwd = fwd->next)
		{
			current = fwd;
			while (current->prev != NULL && current->n < current->prev->n)
			{
				previous = current->prev;
				current->prev = previous->prev;
				previous->next = current->next;

				if (current->next != NULL)
					current->next->prev = previous;

				if (previous->prev != NULL)
					previous->prev->next = current;
				else
					*list = current;

				current->next = previous;
				previous->prev = current;
				swapped = 1;

				print_list(*list);
			}
		}
	} while (swapped != 0);
}
