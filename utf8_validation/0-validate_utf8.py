#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding
"""
from typing import List



def validUTF8(data: List[int]) -> bool:
    """valid utf8"""
    while data:
        li = f'{data[0]:08b}'
        if li[:2] == '10':
            return False
        data.pop(0)
        count = -1
        for i in li:
            if i=='1':
                count+=1
            else:
                break
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
