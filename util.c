#include "monty.h"

/**
 * start_vars - starts
 * @var: global variables
 * Return: 0, or 1
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tmp = 0;
	var->dict = create_instru();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instru - creates new function dictionary
 * Return: pointer to dictionary
 */
instruction_t *create_instru()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: mallloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = divi;
	ptr[9].opcode = "mul", ptr[9].f = mul;
	ptr[10].opcode = "mod", ptr[10].f = mod;
	ptr[11].opcode = "pchar", ptr[11].f = pchar;
	ptr[12].opcode = "pstr", ptr[12].f = pstr;
	ptr[13].opcode = "rotl", ptr[13].f = rotl;
	ptr[14].opcode = "rotr", ptr[145].f = rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = "NULL", ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_funct - call function
 *@var: global variable
 *@opcode: string to check
 *Return: none
 */
int call_funct(vars *var, char *opcode)
{
	int i;

	for (i = 0; var->dict[i].opcode; i++)
		if (strcmp(opcode, var->dict[i].opcode) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * free_all - clean programs
 * Return: nothing
 */
void free_all(void)
{
	if (var.buff != NULL)
		free(var.buff);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - digits
 * @string: string to convert
 * Return: 1 or 0
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
