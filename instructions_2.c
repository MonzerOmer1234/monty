#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * exec_pint - executes the pint instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pint(stack_t** stack, unsigned int line_number) {
    if (!(*stack)) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        return;
    }
    printf("%d\n", (*stack)->n);
}

/**
 * exec_pop - executes the pop instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pop(stack_t** stack, unsigned int line_number) {
    if (!(*stack)) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        return;
    }

    if (state.mode == STACK_MODE) {
        pop_top(stack);
    } else {
        pop_bottom(stack);
    }
}

/**
 * exec_swap - executes the swap instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_swap(stack_t** stack, unsigned int line_number) {
    int* first;
    int* second;
    int temp;

    if (state.stack_size < 2) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        return;
    }

    first = &(*stack)->n;
    second = &(*stack)->prev->n;
    temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * exec_add - executes the add instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_add(stack_t** stack, unsigned int line_number) {
    int* first;
    int* second;

    if (state.stack_size < 2) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        return;
    }

    /* Perform addition: second = second + first */
    first = &(*stack)->n;
    second = &(*stack)->prev->n;
    *second = (*second + *first);

    /* Remove the top element */
    pop_top(stack);
}

/**
 * exec_nop - executes the nop instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_nop(stack_t** stack __attribute__((unused)), unsigned int line_number __attribute__((unused))) {
    state.status = EXIT_SUCCESS;
}
