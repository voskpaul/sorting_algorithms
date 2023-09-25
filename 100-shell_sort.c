#include "sort.h"

void shell_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * shell_sort - for sorting an array from small to large.
 * @array: represents the array to sort.
 * @size: this is arrays size.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, index, jndex;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap = gap / 3)
	{
		for (index = gap; index < size; index++)
		{
			jndex = index;

			while (jndex >= gap && array[jndex - gap] > array[jndex])
			{
				swap_ints(array + jndex, array + (jndex - gap));
				jndex -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap_ints - to Swap two integers in an array.
 * @a: 1st integer to be swapped.
 * @b: 2nd integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
