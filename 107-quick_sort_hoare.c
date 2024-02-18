#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - swaps the positions of two integers within an array.
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
 * hoare_partition - Sorts a portion of an array of integers using the Hoare
 * partitioning method.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Indicates the initial index of the subset to arrange.
 * @right: Denotes the final index of the subset to arrange.
 *
 * Return: Final partition index.
 *
 * Description: *Employs the final element of the partition as the pivot.
 * Shows the array following every exchange of two elements.
 *
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implements the quicksort algorithm recursively.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Indicates the initial index of the subset to arrange.
 * @right: Denotes the final index of the subset to arrange.
 *
 * Description: Applies the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Orders an array of integers in ascending order
 * utilizing the quicksort algorithm.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Utilizes the Hoare partition scheme. Displays the array
 * after swapping two elements.
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
