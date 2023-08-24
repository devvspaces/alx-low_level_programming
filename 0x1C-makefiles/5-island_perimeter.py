#!/usr/bin/python3
"""Defines an island perimeter
measuring function."""


def island_perimeter(grid):
    """Return the perimeter of an island.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for idx in range(height):
        for jdx in range(width):
            if grid[idx][jdx] == 1:
                size += 1
                if (jdx > 0 and grid[idx][jdx - 1] == 1):
                    edges += 1
                if (idx > 0 and grid[idx - 1][jdx] == 1):
                    edges += 1
    return size * 4 - edges * 2
