#include "sort.h"

/**
 * quick_sort_hoare - a function that sorts an array of integers
 * In ascending order using the Quick sort algorithm (Hoare)
 * @array: array to be sorted
 * @size: size of array
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, size, 0, size - 1);
}

/**
 * sort - sorting function, helper function to quick_sort_hoare()
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
	int start, end, pivot;

	start = first_index;
	end = last_index - 1;
	pivot = array[last_index];

	while (start <= end)
	{
		while (array[start] < pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			swap(&array[start], &array[end]);
			print_array(array, size);
		}
	}
	swap(&array[last_index], &array[start]);
	print_array(array, size);
	return (start);
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
