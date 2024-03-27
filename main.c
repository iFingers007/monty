#include "monty.h"
/**
 * main - Introduction to the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always return Zero when succesful
 */
int main(int argc, char *argv[])
{
	FILE *stream = NULL;
	char line[MAX_LIM];
	unsigned int lineNum = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LIM, stream) != NULL)
	{
		char *token = strtok(line, "\t\r\n ");

		if (token == NULL)
		{
			lineNum++;
			continue;
		}
		execCmd(token, &head, lineNum);
		lineNum++;
	}

	freeHead(head);
	fclose(stream);
	return (0);
}
