#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void nop(stack_t **head, unsigned int line_number)
{

	(void)head;
	(void)line_number;
}
/**
 * pchar - prints the char at the top of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	if (temp < 0 || temp > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(temp);
}
