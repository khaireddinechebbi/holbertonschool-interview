#!/usr/bin/python3

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