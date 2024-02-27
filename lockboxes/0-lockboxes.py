#!/usr/bin/python3
'''
    Locboxes
'''

def canUnlockAll (boxes):
    #First box is always open
    opened = [0]
    for i in opened:

        # Concating keys
        opened += list(set(boxes[i])-set(opened))

        # Removing keys with no boxes
        opened = [i for i in opened if i <= len(boxes)]

        #If we got all boxes opened return true
        if len(opened)==len(boxes):
            return True
        
    #Otherwise false
    return False    