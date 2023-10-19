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

/**
 * my_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void my_pop(stack_t **head, int counter)
{
	stack_t *curr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(share.file);
		free(share.oparg);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	curr = *head;
	*head = curr->next;
	if((*head) != NULL)
		(*head)->prev = NULL;
	free(curr);
}
/**
 * my_swap - swap two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void my_swap(stack_t **head, int counter)
{
	stack_t *curr, *first, *second;
	int len = 0, n_temp;

	curr = *head;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = first->next;
	n_temp = first->n;
	first->n = second->n;
	second->n = n_temp;
}

/**
 * my_add - adding the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: nothing
*/
void my_add(stack_t **head, int counter)
{
	stack_t *curr, *first;
	int len = 0;

	curr = *head;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	first->next->n = first->n + first->next->n;
	*head = first->next;
	(*head)->prev = NULL;
	free(first);
}

