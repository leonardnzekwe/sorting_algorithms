#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * In ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, tmp;

	if (size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		swapped = 0;
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
