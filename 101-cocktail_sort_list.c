#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, india;

	for (max = array[0], india = 1; india < size; india++)
	{
		if (array[india] > max)
			max = array[india];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, india;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (india = 0; india < (max + 1); india++)
		count[india] = 0;
	for (india = 0; india < (int)size; india++)
		count[array[india]] += 1;
	for (india = 0; india < (max + 1); india++)
		count[india] += count[india - 1];
	print_array(count, max + 1);

	for (india = 0; india < (int)size; india++)
	{
		sorted[count[array[india]] - 1] = array[india];
		count[array[india]] -= 1;
	}

	for (india = 0; india < (int)size; india++)
		array[india] = sorted[india];

	free(sorted);
	free(count);
}
