#!/usr/bin/python3
"""VALIDATOR ejji"""


def CC(item):
    """count of 1"""
    count = -1
    for i in item:
        if i=='1':
            count+=1
        else:
            break
    return count

def validUTF8(data) -> bool:
    """valid utf8"""
    while data:
        li = f'{data[0]:08b}'
        if li[:2] == '10':
            return False
        data.pop(0)
        count = CC(li)
        if count>=4:
            return False
        if count==-1:
            continue

        while count!=0:
            count-=1
            if not data or f'{data[0]:08b}'[:2] != '10':
                return False
            data.pop(0)
    return True
