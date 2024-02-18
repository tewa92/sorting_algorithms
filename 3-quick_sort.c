#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Organizes a portion of an array of integers based on
 * the Lomuto partition scheme, with the last element serving as the pivot.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Indicates the initial index of the subset to arrange.
 * @right: Denotes the final index of the subset to arrange.
 *
 * Return: Final  index.
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
 * lomuto_sort - Implements the quicksort algorithm recursively.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Indicates the initial index of the subset to arrange.
 * @right: Denotes the final index of the subset to arrange.
 *
 * Description: Applies Lomuto partition scheme.
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
 * quick_sort - Arranges an array of integers in ascending order using the
 * quicksort method.
 * @array: array of integers to sort.
 * @size: size of the array.
 * Description: Employs the Lomuto partitioning method. Displays the
 * array following each interchange of two elements.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
