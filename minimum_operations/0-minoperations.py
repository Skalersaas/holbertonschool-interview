#!/usr/bin/python3
'''
Min ops to get needed count of elements
'''

def minOperations(n):
    if(n==4):
        return 4
    elif(n==3):
        return 3
    elif(n==2):
        return 2
    elif(n==1):
        return 0
    elif(n%2==0):
        return minOperations(n/2) + 2
    else:
        return minOperations(n-3) + 1
