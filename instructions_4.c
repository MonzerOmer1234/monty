#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * exec_pstr - executes the pstr instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *stack_top = *stack;
	while (stack_top && stack_top->n && is_printable_ascii_char(stack_top->n))
	{
		printf("%c", (char)stack_top->n);
		stack_top = stack_top->prev;
	}
	printf("\n");
}

/**
 * exec_rotl - executes the rotl instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *second;
	/* rotl has no effect if stack size is less than 2 */
	if (state.stack_size > 1)
	{
		second = (*stack)->prev;
		second->next = NULL;

		(*stack)->next = state.stack_bottom;
		(*stack)->prev = NULL;
		state.stack_bottom->prev = *stack;
		state.stack_bottom = *stack;

		*stack = second;
	}
}

/**
 * exec_rotr - executes the rotr instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *second_last;
	/* rotr has no effect if stack size is less than 2 */
	if (state.stack_size > 1)
	{
		second_last = state.stack_bottom->next;
		second_last->prev = NULL;

		(*stack)->next = state.stack_bottom;
		state.stack_bottom->next = NULL;
		state.stack_bottom->prev = *stack;
		*stack = state.stack_bottom;

		state.stack_bottom = second_last;
	}
}

/**
 * exec_stack - executes the stack instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_stack(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	state.mode = STACK_MODE;
}

/**
 * exec_queue - executes the queue instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_queue(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	state.mode = QUEUE_MODE;
}
