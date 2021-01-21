#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *palindrome = *head;

    return(recursive(&palindrome, palindrome));
}

/**
 * recursive - compares the half nodes with the other half
 * @left: pointer to first half of list
 * @right: pointer to second half of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int recursive(listint_t **left, listint_t *right)
{
    int result;

    if (right == NULL)
        return (1);
    result = recursive(left, right->next) && (*left)->n == right->n;
    *left = (*left)->next;
    return (result);
}
