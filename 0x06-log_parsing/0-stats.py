#!/usr/bin/python3
"""Log parsing module
    script that reads stdin line by line and computes metrics
"""
#if __name__ == "__main__":
import sys

def print_stats(total_size, code_dict):
    """Method to print the log stats"""
    print("File size: {}".format(total_size))
    for key, value in sorted(code_dict.items()):
        if value != 0:
            print("{}: {}".format(key, value))

count = 0
total_size = 0
code_dict = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

try:
    for line in sys.stdin:
        code = line.split()[-2]
        size = line.split()[-1]
        total_size += int(size)
        count += 1
        if code in code_dict.keys():
            code_dict[code] += 1
        if count == 10:
            print_stats(total_size, code_dict)
            count = 0
    print_stats(total_size, code_dict)
except KeyboardInterrupt:
    print_stats(total_size, code_dict)
    raise
