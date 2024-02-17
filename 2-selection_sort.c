#include "sort.h"

/**
 * swap_ints - swapping of two integers within an array.
 * @a: first integer to be swapped
 * @b: second integer to be swapped
*/

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - arranges an array of integers in ascending order by
 * employing the selection sort algorithm.
 * @array: array of integers to sort.
 * @size: size of the array.
 * 
 * Description: After each swap operation, the function prints the
 * updated array.
*/
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
