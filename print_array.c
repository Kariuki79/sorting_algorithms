#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t india;

	india = 0;
	while (array && india < size)
	{
		if (india > 0)
			printf(", ");
		printf("%d", array[india]);
		++india;
	}
	printf("\n");
}
