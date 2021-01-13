#include "sandpiles.h"
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: grid that contains the sandpile
 * @grid2: grid that contains the sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				my_print_grid(grid1);
				topple(grid1);
			}
		}
	}
}

/**
 * topple - makes the toppling to the sandpiles
 * @grid: grid to toppling
 */
void topple(int grid[3][3])
{
	int i, j;
	int new[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			new[i][j] = grid[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (new[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
			}
		}
	}
	grid = new;
}

/**
 * my_print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void my_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
