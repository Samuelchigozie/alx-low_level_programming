#include "lists.h"

/**
 * function that returns the sum of all the data (n) of a listint_t linked list.
 *
 * if the list is empty, return 0
*/
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		/* add n to sum*/
		sum += head->n;
		/*go to the next node*/
		head = head->next;
	}

	/*if list will be empty it will return sum = 0*/
	return (sum);
}
