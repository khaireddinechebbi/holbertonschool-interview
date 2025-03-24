#include "slide_line.h"
#include <stddef.h>

/**
* slide_line - Slides and merges an array of integers in the 2048 game style.
* @line: Pointer to an array of integers.
* @size: Size of the array.
* @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
*
* Return: 1 upon success, 0 upon failure.
*/
int slide_line(int *line, size_t size, int direction)
{
size_t i, j, last_merged;

if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
return (0);

if (direction == SLIDE_LEFT)
{
last_merged = 0;
for (i = 0, j = 0; i < size; i++)
{
if (line[i] != 0)
{
if (j > 0 && line[j - 1] == line[i] && last_merged != j - 1)
{
line[j - 1] *= 2;
line[i] = 0;
last_merged = j - 1;
}
else if (j != i)
{
line[j] = line[i];
line[i] = 0;
j++;
}
else
j++;
}
}
}
else if (direction == SLIDE_RIGHT)
{
last_merged = size - 1;
for (i = size, j = size; i-- > 0;)
{
if (line[i] != 0)
{
if (j < size && line[j] == line[i] && last_merged != j)
{
line[j] *= 2;
line[i] = 0;
last_merged = j;
}
else if (j - 1 != i)
{
line[j - 1] = line[i];
line[i] = 0;
j--;
}
else
j--;
}
}
}
return (1);
}
