#include "monty.h"
/**
 * my_pchr - prints the char at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void my_pchr(stack_t **head, int counter)
{
	stack_t *curr = *head;

	if (!curr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	if (curr->n > 127 || curr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		free(share.opcode);
		fclose(share.file);
		free_thestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", curr->n);
}

/**
 * my_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line number
 * Return: void
*/
void my_pstr(stack_t **head, int counter)
{
	stack_t *curr;

	counter++;
	curr = *head;
	while (curr)
	{
		if (curr->n > 127 || curr->n <= 0)
			break;
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}

/**
 *my_rotl- rotating the stack to the top
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */
void my_rotl(stack_t **head, int counter)
{
	stack_t *curr = *head, *second;

	counter++;
	if (curr == NULL || curr->next == NULL)
		return;
	second = curr->next;
	second->prev = NULL;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *head;
	(*head)->next = NULL;
	(*head)->prev = curr;
	(*head) = second;
}

/**
*my_rotr- rotates the stack to the right
*@head: stack head
*@counter: line_number
*Return: void
*/
void my_rotr(stack_t **head, int counter)
{
	stack_t *curr;

	curr = *head;
	counter++;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *head;
	curr->prev->next = NULL;
	curr->prev = NULL;
	(*head)->prev = curr;
	*head = curr;
}
