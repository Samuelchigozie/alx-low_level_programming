
Project: Doubly Linked Lists in C

This project focuses on implementing doubly-linked lists in C. It includes tests, a header file, and various functions to perform operations on doubly-linked lists.

Tests:

The "tests" folder contains test files provided by Holberton School.
Header File (lists.h):

This header file contains definitions and prototypes for all the types and functions used in the project.
Types and Files:

Type: dlistint_s

Definition:
int n
struct dlistint_s *prev
struct dlistint_s *next
Type Alias: dlistint_t (alias for struct dlistint_s)

Functions:

print_dlistint (File: 0-print_dlistint.c)

Prints all the elements of a doubly-linked dlistint_t list.
Returns the number of nodes in the list.
dlistint_len (File: 1-dlistint_len.c)

Returns the number of nodes in a doubly-linked dlistint_t list.
add_dnodeint (File: 2-add_dnodeint.c)

Adds a new node at the beginning of a doubly-linked dlistint_t list.
Returns the address of the new element.
Returns NULL if the function fails.
add_dnodeint_end (File: 3-add_dnodeint_end.c)

Adds a new node at the end of a doubly-linked dlistint_t list.
Returns the address of the new element.
Returns NULL if the function fails.
free_dlistint (File: 4-free_dlistint.c)

Frees a doubly-linked dlistint_t list.
get_dnodeint_at_index (File: 5-get_dnodeint.c)

Locates a given node at the specified index in a doubly-linked dlistint_t list.
Returns the address of the located node.
Returns NULL if the node does not exist.
sum_dlistint (File: 6-sum_dlistint.c)

Sums all the data (n) of a doubly-linked dlistint_t list.
Returns 0 if the list is empty.
insert_dnodeint_at_index (File: 7-insert_dnodeint.c)

Inserts a new node at the specified position in a doubly-linked dlistint_t list.
Returns the address of the new element.
Returns NULL if the function fails.
Requires compilation with functions defined in 2-add_dnodeint.c and 3-add_dnodeint_end.c.
delete_dnodeint_at_index (File: 8-delete_dnodeint.c)

Deletes the node at the specified index of a doubly-linked dlistint_t list.
Returns 1 if the deletion is successful.
Returns -1 if the function fails.
Other Files:

100-password: Text file containing the password for the crackme4 executable.

Command to check your code correctly: echo -n "906609" > 102-result
102-result: Text file containing the largest palindrome made from a product of two three-digit numbers.

103-keygen.c: C function that generates passwords for the crackme5 executable.

Usage of the crackme: ./crackme5 username key
Usage of the keygen: ./keygen5 username
