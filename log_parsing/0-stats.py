#!/usr/bin/python3
"""Reads stdin line by line and computes metrics
If count of lines is evenly divided by 10 and/or
keyboardinterrupt
all info will be printed"""

import sys


def print_msg(ids, file_size):
    print("File size:", file_size)
    for key in ids.keys():
        if ids[key] > 0:
            print(f"{key}: {ids[key]}")


def get_values(line):
    nums = line.rstrip().split(' ')
    try:
        ids[int(nums[-2])] += 1
        file_size += int(nums[-1])
    except BaseException:
        pass


file_size = 0
count = 1
ids = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

try:
    for line in sys.stdin:
        get_values(line)

        if count % 10 == 0:
            print_msg(ids,file_size)

        count += 1

finally:
    print_msg(ids,file_size)
