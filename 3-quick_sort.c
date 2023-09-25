#include "sort.h"

void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);
int lomuto_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);

/**
 * quick_sort - An array is sorted in ascending order.
 * @array: to represents the array.
 * @size: represnt's the size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - to execute the quicksort algorithm.
 * @array: represents the array.
 * @size: represnt's the size of array.
 * @left: the start point to sort from.
 * @right: the end point.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * lomuto_partition - to sort a subset of the array.
 * @array: represnts the array.
 * @size: represents the arry's size.
 * @left: the start point.
 * @right: the end point.
 * Return: the final index of the subset.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * swap_ints - two integers in an array are swaped.
 * @a: 1st integer to be swaped.
 * @b: 2nd integer to be swaped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
