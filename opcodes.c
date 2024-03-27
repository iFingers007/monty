#include "monty.h"

/**
 * push - Pushes number to the top of the stack
 * @head: Pointer to the head pointer
 * @line_number: Line number
 * Return: Void
 */
void push(stack_t **head, unsigned int line_number)
{
	int num;
	char *arg;
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp = *head;

	if (head == NULL)
	{
		fprintf(stderr, "Stack is not present\n");
		exit(EXIT_FAILURE);
	}
	arg = strtok(NULL, "\t\r\n");
	if (arg == NULL || isInt(arg) == 0)
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
        num = atoi(arg);
/* Check for malloc failure */
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	new->next = *head;

	if ((*head) != NULL)
		temp->prev = new;
	*head = new;
}

/**
 * pall - prints all the values on the stack, starting from top of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 * Return: Void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 * Return: Void
 */
void pint(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 * Return: Void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
}
/**
 * swap - swaps the top two elements of the stack.
 * @head: Pointer to the head pointer
 * @line_number: Line number
 * Return: Void
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
