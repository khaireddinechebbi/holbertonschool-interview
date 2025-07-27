#!/usr/bin/python3
"""
Function to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    """
    if not grid or not grid[0]:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Start with 4 sides
                perimeter += 4

                # Subtract 1 for each adjacent land cell
                if i > 0 and grid[i - 1][j] == 1:  # top
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:  # bottom
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:  # left
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:  # right
                    perimeter -= 1

    return perimeter
