#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t india, juliet;

	if (array == NULL || size < 2)
		return;

	for (india = 0; india < size - 1; india++)
	{
		min = array + india;
		for (juliet = india + 1; juliet < size; juliet++)
			min = (array[juliet] < *min) ? (array + juliet) : min;

		if ((array + india) != min)
		{
			swap_ints(array + india, min);
			print_array(array, size);
		}
	}
}
