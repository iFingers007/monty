#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void execCmd(char *cmd, stack_t **head, unsigned int line_num);
void freeHead(stack_t *h);
int isInt(char *num);

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
/*Calculator functions*/
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void div_op(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);


#endif
