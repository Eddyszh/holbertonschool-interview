#!/usr/bin/python3
"""Rain algorithm
"""


def rain(walls):
    """calculate how much water will be retained after it rains
    """
    left = 0
    rigth = len(walls) - 1
    level = 0
    water = 0
    while (left < rigth):
        if walls[left] < walls[rigth]:
            low = walls[left]
            left += 1
        else:
            low = walls[rigth]
            rigth -= 1
        if (level < low):
            level = low
        water += level - low
    return water
