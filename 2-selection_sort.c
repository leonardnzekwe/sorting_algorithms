#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * In ascending order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest_index;
	int tmp;

	for (i = 0; i < size; i++)
	{
		smallest_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_index])
			{
				smallest_index = j;
			}
		}
		tmp = array[i];
		array[i] = array[smallest_index];
		array[smallest_index] = tmp;
		print_array(array, size);
	}
}
