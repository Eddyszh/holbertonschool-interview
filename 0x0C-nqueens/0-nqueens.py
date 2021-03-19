#!/usr/bin/python3
"""N queens problem
"""
from sys import argv, exit


def isSafe(board, row, col):
    """Checks if is safe to place a queen"""
    for c in range(col):
        if abs(board[c] - row) is abs(c - col) or board[c] is row:
            return True
    return False


def solveBoard(board, col):
    """Places a queen"""
    board_len = len(board)
    if col is board_len:
        print(str([[c, board[c]] for c in range(board_len)]))
        return
    for row in range(board_len):
        if not isSafe(board, row, col):
            board[col] = row
            solveBoard(board, col + 1)


if __name__ == "__main__":
    n = 0
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(argv[1])
    except:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    board = [0 for i in range(n)]
    solveBoard(board, 0)
