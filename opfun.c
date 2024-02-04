#include  "monty.h"
/**
 * pall - print list
 * @stack: the list
 * @line_number: file line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (tmp == NULL)
	{
		return;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push - insert a new value
 * @stack: linked list
 * @line_number: File line
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (var.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tm->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * pint - prints last node
 * @stack: linked list
 * @line_number: file line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - delete top list
 * @stack: linked list
 * @line_number: file line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}

