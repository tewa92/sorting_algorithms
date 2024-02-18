#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Converts a binary tree into a complete binary heap by
 * rearranging its elements.
 * @array: An array containing integers that represents a binary tree.
 * @size: The size of the array or the number of elements in the binary tree.
 * @base: The index of the base row in the binary tree.
 * @root: The main node of the binary tree.
*/
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Arrange an array of integers in ascending order by employing
 * the heap sort method.
 * @array: Array of the string.
 * @size: Size of thr array.
 *
 * Description: Applies the sift-down heap sort algorithm to organize the
 * elements. Displays the array after each exchange.
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
