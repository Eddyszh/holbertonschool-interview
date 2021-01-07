#!/usr/bin/python3
""" MinOperations module
"""


def minOperations(n):
    """calculates the fewest number of operations needed to result in exactly n H characters"""
    operations = 0
    count = 2
    while n > 1:
        while n % count == 0:
            operations += count
            n /= count
        count += 1
    return operations
