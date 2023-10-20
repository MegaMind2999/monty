#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}

stack_t;

/**
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, int line_number);
} instruction_t;

/**
 *struct sharedds_s - for sharing
 *@opcode: the opcode
 *@curr_line: for sharing
 *@oparg: for sharing
 *@is_stack: for sharing
 *@file: for sharing
 *Description: for sharing
 */
typedef struct sharedds_s
{
	FILE *file;
	char *curr_line;
	char *opcode;
	char *oparg;
	int is_stack;
} sharedds_t;
extern sharedds_t share;


void free_thestack(stack_t *stack);
void my_pint(stack_t **head, int counter);
void my_pall(stack_t **head, int counter);
void push_exit(int line_number, stack_t *stack_index);
void my_push(stack_t **head, int line_number);
int execute_op(stack_t **stack, char *line, int counter);
int main(int argc, char *argv[]);
void my_pop(stack_t **head, int counter);
void my_swap(stack_t **head, int counter);
void my_add(stack_t **head, int counter);
void my_nop(stack_t **head, int counter);
void my_sub(stack_t **head, int counter);
void my_div(stack_t **head, int counter);
void my_mul(stack_t **head, int counter);
void my_mod(stack_t **head, int counter);
void my_pchr(stack_t **head, int counter);
void my_pstr(stack_t **head, int counter);
void my_rotl(stack_t **head, int counter);
void my_rotr(stack_t **head, int counter);
void my_s(stack_t **head, int counter);
void my_q(stack_t **head, int counter);
#endif
