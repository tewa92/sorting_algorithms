#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sorts a bitonic sequence found within an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @start: Identifies the initial index of the sequence within the array to
 * be sorted.
 * @seq: Indicates the size of the sequence to be sorted.
 * @flow: Specifies the direction in which the sequence should be sorted.
*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Transforms an array of integers into a bitonic sequence.
 * @array: A collection of integer values.
 * @size: The number of elements in the array.
 * @start: The index from which the bitonic sequence building block starts
 * in the array.
 * @seq: The length of a block of the bitonic sequence being constructed.
 * @flow: The sorting direction of the block of the bitonic sequence
 * being constructed.
*/
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Implement the bitonic sort algorithm to sort an
 * array of integers in ascending order.
 * @array: A collection of integer values.
 * @size: The number of elements in the array.
 * 
 * Description: Displays the array after each exchange. It's specifically
 * designed for sizes that are powers of 2 (2^k) where k is a non-negative
 * integer.
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
