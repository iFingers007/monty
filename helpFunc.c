#include "monty.h"
/**
 * execCmd - Executes corresponding opcode
 * @cmd: Command token
 * @head: Pointer to the head
 * @line_number: Line number
 *
 * Return: Always return Zero when succesful
 */
void execCmd(char *cmd, stack_t **head, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t code[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div_op},
		{"mod", mod},
/*		{"pchar", pchar},
		{"pstr", pstr}, */
		{NULL, NULL}
	};

	if (*cmd == '#')
		return;
	while (code[i].opcode != NULL)
	{
		if (strcmp(code[i].opcode, cmd) == 0)
		{
			code[i].f(head, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}
/**
 * isInt - Checks if the number is an integer
 * @num: Array of character argument
 *
 * Return: 1 if it is and 0 otherwise
 */
int isInt(char *num)
{
	if (*num == '\0')
		return (0);
	if (*num == '-')
		num++;
	while (*num != '\0')
	{
		if (*num < '0' || *num > '9')
			return (0);
		num++;
	}

	return (1);
}
/**
 * freeHead - Frees the head
 * @head: Head pointer
 *
 * Return: Void
 */
void freeHead(stack_t *head)
{
	stack_t *temp = NULL;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
