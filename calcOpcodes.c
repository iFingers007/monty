#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	pop(head, line_number);
}
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, line_number);
}
/**
 * div_op - divides the second top element of the stack by the
 * top element of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void div_op(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L<%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop(head, line_number);
}
/**
 * mul -  multiplies the second top element of the stack
 * with the top element of the stack
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	pop(head, line_number);
}
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 *
 * Return: Void
 */
void mod(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L<%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	pop(head, line_number);
}
