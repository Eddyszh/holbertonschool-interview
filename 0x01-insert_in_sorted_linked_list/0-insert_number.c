#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to struct
 * @number: value to insert
 * Return: the addres of the new elemen or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *temp = NULL;

	if (!head || !new)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}

	if (new->n < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp->next != NULL)
	{
		if (new->n <= temp->next->n)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		temp = temp->next;
	}
	temp->next = new;
	return (new);
}
