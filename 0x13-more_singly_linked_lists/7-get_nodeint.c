#include "lists.h"

/**
 * function that returns the nth node of a listint_t linked list.
 * index is the index of the node, starting at 0
 *
 * if the node does not exist, return NULL
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	/*iterate thorugh nodes in list till the index nth node*/
	for (i = 0; i < index && head != NULL; i++)
		head = head->next;

	/*return head*/
	return (head);
}
