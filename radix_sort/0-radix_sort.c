#include "sort.h"
#include <stdlib.h>

/**
* get_max - Finds the maximum number in the array
* @array: The array to check
* @size: Number of elements in array
* Return: Maximum number
*/
int get_max(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
* counting_sort - A stable counting sort based on a specific digit
* @array: The array to sort
* @size: Size of the array
* @digit: Digit to sort by (1, 10, 100, ...)
*/
void counting_sort(int *array, size_t size, int digit)
{
int count[10] = {0};
int *output = malloc(sizeof(int) * size);
size_t i;

if (!output)
return;

/* Count digit occurrences */
for (i = 0; i < size; i++)
count[(array[i] / digit) % 10]++;

/* Accumulate counts */
for (i = 1; i < 10; i++)
count[i] += count[i - 1];

/* Build output array in reverse to maintain stability */
for (i = size; i > 0; i--)
{
int idx = (array[i - 1] / digit) % 10;
output[count[idx] - 1] = array[i - 1];
count[idx]--;
}

/* Copy output back to array */
for (i = 0; i < size; i++)
array[i] = output[i];

print_array(array, size);
free(output);
}

/**
* radix_sort - Sorts an array using LSD Radix Sort
* @array: The array to sort
* @size: Size of the array
*/
void radix_sort(int *array, size_t size)
{
int max, digit;

if (!array || size < 2)
return;

max = get_max(array, size);

for (digit = 1; max / digit > 0; digit *= 10)
counting_sort(array, size, digit);
}
