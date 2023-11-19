#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - removes all elements from the stack
 *
 * @stack: pointer to the stack
 *
 */
void free_stack(stack_t **stack)
{
	while (state.stack_size > 0)
		pop_top(stack);
}
