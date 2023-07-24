#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * In ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
*/

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, size, 0, size - 1);
}

/**
 * sort - sorting function, helper function to quick_sort()
 * @array: array to be sorted
 * @size: size of the array
 * @first_index: first index of the array
 * @last_index: last index of the array
*/

void sort(int *array, size_t size, int first_index, int last_index)
{
	if (first_index < last_index)
	{
		int pivot_index;

		pivot_index = partition(array, size, first_index, last_index);

		sort(array, size, first_index, pivot_index - 1);
		sort(array, size, pivot_index + 1, last_index);
	}
}

/**
 * partition - partitioning function, helper function to sort()
 * @array: array to be sorted
 * @size: sizze of the array
 * @first_index: first index of the array
 * @last_index: last index of the array
 * Return: pivot_index
*/

int partition(int *array, size_t size, int first_index, int last_index)
{
	int i, j, pivot;

	i = first_index - 1;
	pivot = array[last_index];
	for (j = first_index; j < last_index; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != last_index)
	{
		swap(&array[i + 1], &array[last_index]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - swapping function, helper function to partition()
 * @a: first item to be swapped
 * @b: second item to be swapped
*/

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
