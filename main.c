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
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	unsigned int lineNum = 1;
	ssize_t nread;
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
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		char *token = strtok(line, "\n\t\r ");

		if (token == NULL)
		{
			lineNum++;
			continue;
		}
		execCmd(token, &head, lineNum);
		lineNum++;
	}

	free(line);
	freeHead(head);
	fclose(stream);
	return (0);
}
