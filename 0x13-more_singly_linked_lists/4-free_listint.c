#include "lists.h"

/**
 * function that frees a listint_t list.
 *
 * Return: nothing
*/
void free_listint(listint_t *head)
{
	listint_t *current;

	/*iterate through each node in list*/
	while ((current = head) != NULL)
	{
		/*set head as the next node*/
		head = head->next;
		free(current);
	}
}
