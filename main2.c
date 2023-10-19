#include "monty.h"

/**
* free_thestack - frees a doubly linked list
* return: nothing
*/
void free_thestack(stack_t *stack)
{
	stack_t *tmp, *temp;

	tmp = stack;
	if (tmp == NULL)
		return;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		temp = tmp->next;
		free(tmp);
		tmp = temp;
	}
}

/**
 * my_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: nothing
*/
void my_pint(stack_t **head, int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(share.file);
		free(share.opcode);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
