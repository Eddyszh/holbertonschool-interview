#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: elements that must be slided
 * @direction: direction can be either; SLIDE_LEFT, SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;
	int temp = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 1; i < size && line[i] != 0; i++)
		{
			if (line[i - 1]  == line[i])
			{
				line[i - 1] *= 2;
				line[i] = 0;
				temp = 1;
			}
		}
		if (temp)
			slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; i > 0 && line[i - 1] != 0; i--)
		{
			if (line[i - 1] == line[i])
			{
				line[i] *= 2;
				line[i - 1] = 0;
				temp = 1;
			}
		}
		if (temp)
			slide_right(line, size);
	}
	else
	{
		return (0);
	}
	return (1);
}

/**
 * slide_right - slides the array to the right
 * @line: points to an array of integers containing size elements
 * @size: elements that must be slided
 */
void slide_right(int *line, size_t size)
{
	int i, temp, current = size - 1;

	for (i = size - 1; i >= 0 && current >= 0; i--)
	{
		while (current > 0 && line[current] != 0)
			current--;
		if (line[i] != 0 && i < (int)current)
		{
			temp = line[i];
			line[i] = line[current];
			line[current] = temp;
		}
	}
}

/**
 * slide_left - slides the array to the left
 * @line: points to an array of integers containing size elements
 * @size: elements that must be slided
 */
void slide_left(int *line, size_t size)
{
	int i, temp, current = 0;

	for (i = 0; i < (int)size && current < (int)size; i++)
	{
		while (line[current] != 0)
			current++;
		if (line[i] != 0 && i > current)
		{
			temp = line[i];
			line[i] = line[current];
			line[current] = temp;
		}
	}
}
