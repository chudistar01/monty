#include "monty.h"

/**
 * rotl - rotates list to left
 * @stack: linked list
 * @line_number: file line
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tm = *stack;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (tm->next)
		tm = tm->next;
	(*stack) = (*stack)->next;
	tm->next->next = NULL;
	tm->next->prev = tm;
}


/**
 * rotr - rotates lists to the right
 * @stack: linked list
 * @line_number: file line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	(*stack)->prev = tmp;
	*stack = tmp;
}


/**
 * stack - stack operation
 * @stack: linked list
 * @line_number: file line
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 0;
}


/**
 * queue - stack operation
 * @stack: linked list
 * @line_number: file line
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 1;
}
