#include "sort.h"

/**
 * swap_ints - two integers swap in an array
 * @a: first integer to be swaped
 * @b: second integer to be swaped
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order utilizing the
 * shell sort algorithm.
 * @array: array of integers to sort.
 * @size: size of the array.
 *
 * Description: Implements the Knuth interval sequence for sorting.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
