#include "lists.h"

/**
 * function that inserts a new node at a given position.
 * idx is the index of the list where the new node should be added
 * Returns: the address of the new node, or NULL if it failed
 *
 * if it is not possible to add the new node at index idx, do not add the new node and return NULL
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int index;

	current = *head; /*place first node at current*/

	new_node = malloc(sizeof(listint_t));
	if ((*head == NULL && idx != 0) || new_node == NULL)
		return (NULL);

	new_node->n = n; /* adding some elements to the new node*/

	/*iterate list to node position idx - 2*/
	for (index = 0; head != NULL && index < idx - 1; index++)
	{
		current = current->next;
		if (current == NULL)
			return (NULL);
	}

	if (idx == 0) /*if the index for new node is 0*/
	{
		/*Moving 1st node to the 2nd one*/
		new_node->next = *head;
		/*The new node is now placed as the 1st node*/
		*head = new_node;
	}
	else if (current->next) /*if index where to add our new node is not 0*/
	{
		new_node->next = current->next; /*place current node after new node*/
		current->next = new_node;/*set the new node at index idx*/
	}
	else /*if node position is not present in the list*/
	{
		new_node->next = NULL;/*set next address as NULL, showing it the last node*/
		current->next = new_node;/*set the new node at the last position in list*/
	}

	return (new_node);
}
