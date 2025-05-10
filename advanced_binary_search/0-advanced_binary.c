#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the array
 * @low: Start index
 * @high: End index
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence of value
 * @array: Pointer to the array
 * @low: Start index
 * @high: End index
 * @value: The value to search for
 *
 * Return: Index of first occurrence, or -1
 */
int recursive_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);

	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (recursive_search(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (recursive_search(array, mid + 1, high, value));
	else
		return (recursive_search(array, low, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value using advanced binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
