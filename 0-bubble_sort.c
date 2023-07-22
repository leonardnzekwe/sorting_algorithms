#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * In ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, no_of_items;
	int swapped, temp, *prev, *next;

	if (size < 2)
		return;
	no_of_items = size - 1;
	for (j = 0; j < no_of_items; j++)
	{
		swapped = 0;
		for (i = 0; i < no_of_items - j; i++)
		{
			prev = &array[i];
			next = &array[i + 1];
			if (*prev > *next)
			{
				temp = *next;
				*next = *prev;
				*prev = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
