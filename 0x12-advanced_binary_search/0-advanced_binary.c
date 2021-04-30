#include "search_algos.h"
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the index where value is located, -1 if failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	int res;

	if (!array)
		return (-1);
	res = find_value(array, 0, size - 1, value);
	return (res);
}

/**
 * find_value - recursive function to find value position
 * @arr: pointer to new array element of the array to search in
 * @left: the index
 * @right: size of the array
 * @value: value to search for
 * Return: the index where value is located, -1 on failure
 */
int find_value(int *arr, int left, int right, int value)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		print_array(arr, left, right);
		if (arr[mid] == value)
		{
			if (arr[mid - 1] == value)
				return (find_value(arr, left, mid, value));
			return (mid);
		}
		if (arr[mid] > value)
			return (find_value(arr, left, mid, value));
		else
			return (find_value(arr, mid + 1, right, value));
	}
	return (-1);
}

/**
 * print_array - Prints the array
 * @arr: pointer to array
 * @left: starting point
 * @right: ending point
 */
void print_array(int *arr, int left, int right)
{
	int i = left;

	printf("Searching in array:");
	while (i < right)
	{
		printf(" %i,", arr[i]);
		i++;
	}
	printf(" %i\n", arr[i]);
}
