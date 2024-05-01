#!/usr/bin/python3
"""UTF-8 validator"""


def validUTF8(data):
    """Function"""
    count = 0
    while data:
        binary = bin(data[0])[2:].rjust(8, '0')[:2]
        data.pop(0)
        if count == 0:
            match binary:
                case "11":
                    count = 1
                case "111":
                    count = 2
                case "1111":
                    count = 3
                case "10":
                    return False
        else:
            if binary != "10":
                return False
            count -= 1
    if count != 0:
        return False
    return True
