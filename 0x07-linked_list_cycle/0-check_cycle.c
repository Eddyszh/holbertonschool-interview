#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *first, *second;

	first = list;
	second = list;

	while (first && first->next)
	{
		first = first->next->next;
		second = second->next;
		if (first == second)
			return (1);
	}
	return (0);
}
