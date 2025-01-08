#!/usr/bin/python3
"""
This module provides a solution to the Lockboxes problem.

The `canUnlockAll` function determines whether all boxes in a list of lists
can be unlocked given their contents (keys to other boxes).
"""
def canUnlockAll(boxes):
    unlocked = set()
    unlocked.add(0)
    keys = set(boxes[0])

    while keys:
        key = keys.pop()
        if key < len(boxes) and key not in unlocked:
            unlocked.add(key)
            keys.update(boxes[key])
    
    return len(unlocked) == len(boxes)