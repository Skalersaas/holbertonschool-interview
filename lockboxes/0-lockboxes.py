#!/usr/bin/python3
# Lockboxes
if __name__ == "__main__":
    def canUnlockAll(boxes):
        opened = [0]
        for i in opened:
            box = boxes[i]
            opened += list(set(box)-set(opened))
            if len(opened)==len(boxes):
                return True
            
        return False    