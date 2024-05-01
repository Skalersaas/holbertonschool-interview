#!/usr/bin/python3
"""UTF-8 validator"""


def validUTF8(data) -> bool:
    """Function"""
    if sum(item > 255 for item in data) > 0:
        return False
    return True
