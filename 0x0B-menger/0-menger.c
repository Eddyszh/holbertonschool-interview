#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */

void menger(int level)
{
	int i, j, size;

	if (level == 0)
	{
		printf("#\n");
		return;
	}
	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (sponge(i, j) == 1)
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}

/**
 * sponge - posicionates the sponges
 * @row: row size
 * @col: column size
 * Return: 1 if is posible to put a sponge 0 otherwise
 */
int sponge(int row, int col)
{
	int res = 0;

	if (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return (1);
		}
		else
		{
			res = sponge(row / 3, col / 3);
		}
		if (res == 1)
			return (1);
	}
	return (0);
}
