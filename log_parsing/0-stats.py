#!/usr/bin/python3

'''
Reads stdin line by line and computes metrics
'''
import sys

if __name__ == "__main__":


    file_size: int = 0
    ids = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0}
    count = 0


    def parse(line):
        '''Parses input line and returns last two values'''
        nums = line.rstrip().split(' ')
        try:
            return [int(nums[7]), int(nums[8])]
        finally:
            return None


    def write_info():
        '''Writes info to the terminal'''
        print("File size:", file_size)
        for key in ids.keys():
            if ids[key] > 0:
                print(f"{key}: {ids[key]}")


    while True:
        try:
            for line in sys.stdin:
                if count == 9:
                    write_info()
                    count = 0
                else:
                    nums = parse(line)
                    if nums and nums[0] and nums[1]:
                        ids[nums[0]] += 1
                        file_size += nums[1]
                        count += 1
        except KeyboardInterrupt:
            write_info()
