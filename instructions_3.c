#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * exec_sub - executes the sub instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_sub(stack_t** stack, unsigned int line_number) {
    int* first;
    int* second;

    if (state.stack_size < 2) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        return;
    }

    /* Perform subtraction: second = second - first */
    first = &(*stack)->n;
    second = &(*stack)->prev->n;
    *second = (*second - *first);

    /* Remove the top element */
    pop_top(stack);
}

/**
 * exec_div - executes the div instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_div(stack_t** stack, unsigned int line_number) {
    int* first;
    int* second;

    if (state.stack_size < 2) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        return;
    }

    first = &(*stack)->n;
    second = &(*stack)->prev->n;

    if (*first == 0) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: division by zero\n", line_number);
        return;
    }

    /* Perform division: second = second / first */
    *second = (*second / *first);

    /* Remove the top element */
    pop_top(stack);
}

/**
 * exec_mul - executes the mul instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_mul(stack_t** stack, unsigned int line_number) {
    int* first;
    int* second;

    if (state.stack_size < 2) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        return;
    }

    /* Perform multiplication: second = second * first */
    first = &(*stack)->n;
    second = &(*stack)->prev->n;
    *second = (*second * *first);

    /* Remove the top element */
    pop_top(stack);
}

/**
 * exec_mod - executes the mod instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_mod(stack_t** stack, unsigned int line_number) {
    int* first;
    int* second;

    if (state.stack_size < 2) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        return;
    }

    first = &(*stack)->n;
    second = &(*stack)->prev->n;

    if (*first == 0) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: division by zero\n", line_number);
        return;
    }

    /* Perform modulus: second = second % first */
    *second = (*second % *first);

    /* Remove the top element */
    pop_top(stack);
}

/**
 * exec_pchar - executes the pchar instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pchar(stack_t** stack, unsigned int line_number) {
    int first;

    if (!(*stack)) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        return;
    }

    first = (*stack)->n;

    if (!is_printable_ascii_char(first)) {
        state.status = EXIT_FAILURE;
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        return;
    }

    printf("%c\n", (char)first);
}