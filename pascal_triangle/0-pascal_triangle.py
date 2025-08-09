#!/usr/bin/python3
"""
Module: pascal_triangle

This module provides a function to generate Pascal's triangle
up to a given number of rows.
"""


def pascal_triangle(n):
    """
    Generate Pascal's triangle up to n rows.

    Pascal's triangle is a triangular array of the binomial
    coefficients. Each number is the sum of the two numbers
    directly above it.

    Args:
        n (int): The number of rows to generate. Must be a positive integer.

    Returns:
        list[list[int]]: A list of lists of integers representing
                         the first n rows of Pascal's triangle.
                         Returns an empty list if n <= 0.

    Example:
        >>> pascal_triangle(5)
        [
            [1],
            [1, 1],
            [1, 2, 1],
            [1, 3, 3, 1],
            [1, 4, 6, 4, 1]
        ]
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]

        for j in range(1, i):
            new_row.append(prev_row[j - 1] + prev_row[j])

        new_row.append(1)
        triangle.append(new_row)

    return triangle
