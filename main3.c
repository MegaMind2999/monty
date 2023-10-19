#include "monty.h"
/**
*my_nop- no op
*@head: stack head
*@counter: line_number
*Return: void
*/
void my_nop(stack_t **head, int counter)
{
	counter++;
	head++;
}
/**
*my_sub- sub first two
*@head: stack head
*@counter: line_number
*Return: void
*/
void my_sub(stack_t **head, int counter)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	first->next->n = first->next->n - first->n;
	*head = first->next;
	(*head)->prev = NULL;
	free(first);
}

/**
*my_div- div first two
*@head: stack head
*@counter: line_number
*Return: void
*/
void my_div(stack_t **head, int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first->next->n = first->next->n / first->n;
	*head = first->next;
	(*head)->prev = NULL;
	free(first);
}

/**
*my_mul- mul first two
*@head: stack head
*@counter: line_number
*Return: void
*/
void my_mul(stack_t **head, int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	first->next->n = first->next->n * first->n;
	*head = first->next;
	(*head)->prev = NULL;
	free(first);
}

/**
*my_mod- div first two
*@head: stack head
*@counter: line_number
*Return: void
*/
void my_mod(stack_t **head, int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	first->next->n = first->next->n % first->n;
	*head = first->next;
	(*head)->prev = NULL;
	free(first);
}




