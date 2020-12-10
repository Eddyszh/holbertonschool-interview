#!/usr/bin/python3
"""Lockboxes module"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    key = [0]
    for box in range(len(boxes)):
        if box == 0 or box in key:
            key += boxes[box]
    for box in range(len(boxes)):
        if box in key:
            key += boxes[box]
            continue
        else:
            return False
    return True;


