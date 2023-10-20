#include "monty.h"

/**
 * my_q - turns on queue mode
 * @head: stack head
 * @counter: line_number
 * Return: nothing
*/
void my_q(stack_t **head, int counter)
{
	head++;
	counter++;
	share.is_stack = 0;
}
/**
 * my_s - turns on stack mode
 * @head: stack head
 * @counter: line_number
 * Return: nothing
*/
void my_s(stack_t **head, int counter)
{
	head++;
	counter++;
	share.is_stack = 1;
}
