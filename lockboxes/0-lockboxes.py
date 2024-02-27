#!/usr/bin/python3
'''
    Locboxes
'''


def canUnlockAll (boxes):
    # First box is always open
    opened = [0]
    id = 0
    while id < len(opened):
        box = boxes[opened[id]]
        # Concating keys
        opened += list(set(box)-set(opened))
        # Removing keys with no boxes
        opened = [i for i in opened if i < len(boxes)]
        # iterating
        id+=1
        # If we got all boxes opened return true
        if len(opened) == len(boxes):
            return True

    # Otherwise false
    return False