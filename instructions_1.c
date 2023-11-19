#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * exec - executes the given instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", &exec_push},
		{"pall", &exec_pall},
		{"pint", &exec_pint},
		{"pop", &exec_pop},
		{"swap", &exec_swap},
		{"add", &exec_add},
		{"nop", &exec_nop},
		{"sub", &exec_sub},
		{"div", &exec_div},
		{"mul", &exec_mul},
		{"mod", &exec_mod},
		{"pchar", &exec_pchar},
		{"pstr", &exec_pstr},
		{"rotl", &exec_rotl},
		{"rotr", &exec_rotr},
		{"stack", &exec_stack},
		{"queue", &exec_queue}
	};
	unsigned long int i;
	unsigned long instructions_count = sizeof(instructions)
			/ sizeof(instruction_t);
	for (i = 0; i < instructions_count; i++)
	{
		if (!strcmp(state.args[0], instructions[i].opcode))
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, state.args[0]);
	state.status = EXIT_FAILURE;
}

/**
 * pop_top - removes the top element of the stack
 *
 * @stack: pointer to the stack
 */
void pop_top(stack_t **stack)
{
	/* Update the stack pointer */
	stack_t *current = *stack;
	*stack = (*stack)->prev;

	/* Set the next pointer of the new stack if it is not empty */
	if (*stack)
		(*stack)->next = NULL;
	else
		state.stack_bottom = NULL;

	/* Decrement stack size */
	state.stack_size--;

	/* Deallocate the popped element's memory */
	free(current);
}

/**
 * pop_bottom - removes the bottom element of the stack
 *
 * @stack: pointer to the stack
 */
void pop_bottom(stack_t **stack)
{
	/* Update the stack bottom pointer */
	stack_t *current = state.stack_bottom;

	state.stack_bottom = state.stack_bottom->next;

	/* Set the prev pointer of the stack bottom if stack is not empty */
	if (state.stack_bottom)
		state.stack_bottom->prev = NULL;
	else
		*stack = NULL;

	/* Decrement stack size */
	state.stack_size--;

	/* Deallocate the popped element's memory */
	free(current);
}

/**
 * exec_push - executes the push instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack_entry = malloc(sizeof(stack_t));
	int operand;

	if (!new_stack_entry)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	if (state.arg_count < 2 || !is_valid_integer(state.args[1]))
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return;
	}
	else
	{
		operand = atoi(state.args[1]);
	}

	new_stack_entry->n = operand;
	new_stack_entry->next = NULL;
	new_stack_entry->prev = *stack;

	if (*stack)
	{
		if (state.mode == STACK_MODE)
		{
			(*stack)->next = new_stack_entry;
			*stack = (*stack)->next;
		}
		else
		{
			new_stack_entry->next = state.stack_bottom;
			new_stack_entry->prev = NULL;
			state.stack_bottom->prev = new_stack_entry;
			state.stack_bottom = new_stack_entry;
		}
	}
	else
	{
		*stack = new_stack_entry;
		state.stack_bottom = *stack;
	}

	/* Increment stack size */
	state.stack_size++;
}

/**
 * exec_pall - executes the pall instruction
 *
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 *
 */
void exec_pall(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
