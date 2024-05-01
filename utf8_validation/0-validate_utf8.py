#!/usr/bin/python3
"""UTF-8 validator"""


def validUTF8(data):
    """Function"""
    
    while data:
        li = bin(data[0]).replace('0b', '').rjust(8, '0')[-8:]
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
            if not data or bin(data[0]).replace('0b', '').rjust(8, '0')[-8:][:2] != '10':
                return False
            data.pop(0)
    return True
