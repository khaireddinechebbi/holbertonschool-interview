#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right);
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right);

/**
* merge_sort - Sorts an array using the top-down merge sort algorithm
* @array: The array to sort
* @size: The size of the array
*/
void merge_sort(int *array, size_t size)
{
int *buffer;

if (!array || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (!buffer)
return;

merge_sort_recursive(array, buffer, 0, size);
free(buffer);
}

/**
 * merge_sort_recursive - Recursively splits and sorts sub-arrays
 * @array: The main array being sorted
 * @buffer: Temporary array used for merging
 * @left: Starting index of the sub-array
 * @right: Ending index (non-inclusive) of the sub-array
 */
void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right)
{
size_t mid;

if (right - left <= 1)
return;

mid = (left + right) / 2;
merge_sort_recursive(array, buffer, left, mid);
merge_sort_recursive(array, buffer, mid, right);
merge(array, buffer, left, mid, right);
}

/**
 * merge - Merges two sorted sub-arrays into one
 * @array: The original array containing the sub-arrays
 * @buffer: Temporary array used for merging
 * @left: Starting index of the first sub-array
 * @mid: Ending index of the first sub-array / starting of the second
 * @right: Ending index (non-inclusive) of the second sub-array
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = left;

printf("Merging...\n");
printf("[left]: ");
print_array(array + left, mid - left);
printf("[right]: ");
print_array(array + mid, right - mid);

while (i < mid && j < right)
buffer[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

while (i < mid)
buffer[k++] = array[i++];

while (j < right)
buffer[k++] = array[j++];

for (i = left; i < right; i++)
array[i] = buffer[i];

printf("[Done]: ");
print_array(array + left, right - left);
}
