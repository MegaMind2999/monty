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
 * f_pall - print all the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void my_pall(stack_t** head, int counter)
{
	stack_t* curr;

	counter++;
	curr = *head;
	if (curr == NULL)
		return;
	while (curr->prev)
		curr = curr->prev;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void my_push(stack_t** head, int line_number)
{
	stack_t* stack_index = *head, *newnode;
	int i = 0, not_a_num = 0;
	if (!share.oparg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(share.file);
		free(share.curr_line);
		free_thestack(stack_index);
		exit(EXIT_FAILURE);
	}
	if (share.oparg[0] == '-')
		i++;
	while (share.oparg[i] != '\0')
	{
		if (share.oparg[i] > '9' || share.oparg[i] < '0')
			not_a_num = 1;
		i++;
	}
	if (not_a_num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(share.file);
		free(share.curr_line);
		free_thestack(stack_index);
		exit(EXIT_FAILURE);
	}
	newnode = (stack_t*) malloc(sizeof(stack_t));
	if (newnode == NULL)
		exit(1);
	if (!stack_index)
	{
		*head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
		newnode->n = atoi(share.oparg);
	}
	else
	{
		while (stack_index->prev)
			stack_index = stack_index->prev;
		stack_index->prev = newnode;
		newnode->prev = NULL;
		newnode->next = stack_index;
		newnode->n = atoi(share.oparg);
		*head = newnode;
	}
}
/**
* execute_op - executing the opcode
* @counter: line_counter
* @line: line content
* Return: 0 or 1
*/
int execute_op(stack_t** stack, char* line, int counter)
{
	instruction_t opcodes[] = { {"push", my_push}, {"pall", my_pall} ,{NULL, NULL} };
	int i = 0;

	share.opcode = strtok(line, "\n \t");
	if (share.opcode && share.opcode[0] == '#')
		return (0);
	share.oparg = strtok(NULL, "\n \t");
	if (share.opcode)
	{
		while (opcodes[i].opcode && share.opcode)
		{
			if (strcmp(share.opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(stack, counter);
				return (0);
			}
			i++;
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, share.opcode);
		fclose(share.file);
		free(line);
		free_thestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int main(int argc, char* argv[])
{
	ssize_t line_size = 1;
	size_t size = 1024;
	char *buffer;
	stack_t* stack = NULL;
	int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}
	share.file = fopen(argv[1], "r");
	if (!share.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return(EXIT_FAILURE);
	}
	while (line_size !=-1)
	{
		buffer = NULL;
		line_size = getline(&buffer, &size, share.file);
		share.curr_line = buffer;
		counter++;
		if (line_size > 0)
		{
			execute_op(&stack, buffer, counter);
		}
		free(buffer);
	}
	free_thestack(stack);
	fclose(share.file);
    return (0);
}
