#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - Slides and merges an array of integers like 2048 game.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, pos;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        /* Step 1: Shift non-zero elements to the left */
        pos = 0;
        for (i = 0; i < size; i++)
            if (line[i] != 0)
                line[pos++] = line[i];

        /* Fill remaining positions with zero */
        for (; pos < size; pos++)
            line[pos] = 0;

        /* Step 2: Merge adjacent equal elements */
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        /* Step 3: Shift non-zero elements again */
        pos = 0;
        for (i = 0; i < size; i++)
            if (line[i] != 0)
                line[pos++] = line[i];

        for (; pos < size; pos++)
            line[pos] = 0;
    }
    else /* SLIDE_RIGHT */
    {
        /* Step 1: Shift non-zero elements to the right */
        pos = size - 1;
        for (i = size; i > 0; i--)
            if (line[i - 1] != 0)
                line[pos--] = line[i - 1];

        for (; (int)pos >= 0; pos--)
            line[pos] = 0;

        /* Step 2: Merge adjacent equal elements */
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }

        /* Step 3: Shift non-zero elements again */
        pos = size - 1;
        for (i = size; i > 0; i--)
            if (line[i - 1] != 0)
                line[pos--] = line[i - 1];

        for (; (int)pos >= 0; pos--)
            line[pos] = 0;
    }
    return (1);
}
