#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdbool.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s {
    int n;
    struct stack_s* prev;
    struct stack_s* next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t** stack, unsigned int line_number);
} instruction_t;

#define STACK_MODE 0
#define QUEUE_MODE 1

typedef struct state_s {
    stack_t* stack_bottom;  /* Pointer to the bottom of the stack */
    int stack_size;         /* The size of the stack */
    char** args;            /* The opcode and its arguments */
    int arg_count;          /* The number of arguments */
    int mode;               /* The operating mode - 0: stack, 1: queue */
    int status;             /* The status code for the last instruction -
                            * 0: sucess, -1: failure */
} state_t;

extern state_t state;

/**
 * exec - executes the given instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec(stack_t** stack, unsigned int line_number);

/**
 * pop_top - removes the top element of the stack
 * 
 * @stack: pointer to the stack
*/
void pop_top(stack_t** stack);

/**
 * pop_bottom - removes the bottom element of the stack
 * 
 * @stack: pointer to the stack
*/
void pop_bottom(stack_t** stack);

/**
 * exec_push - executes the push instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_push(stack_t** stack, unsigned int line_number);

/**
 * exec_pall - executes the pall instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pall(stack_t** stack, unsigned int line_number);

/**
 * exec_pint - executes the pint instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pint(stack_t** stack, unsigned int line_number);

/**
 * exec_pop - executes the pop instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pop(stack_t** stack, unsigned int line_number);

/**
 * exec_swap - executes the swap instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_swap(stack_t** stack, unsigned int line_number);

/**
 * exec_add - executes the add instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_add(stack_t** stack, unsigned int line_number);

/**
 * exec_nop - executes the nop instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_nop(stack_t** stack, unsigned int line_number);

/**
 * exec_sub - executes the sub instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_sub(stack_t** stack, unsigned int line_number);

/**
 * exec_div - executes the div instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_div(stack_t** stack, unsigned int line_number);

/**
 * exec_mul - executes the mul instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_mul(stack_t** stack, unsigned int line_number);

/**
 * exec_mod - executes the mod instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_mod(stack_t** stack, unsigned int line_number);

/**
 * exec_pchar - executes the pchar instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pchar(stack_t** stack, unsigned int line_number);

/**
 * exec_pstr - executes the pstr instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_pstr(stack_t** stack, unsigned int line_number);

/**
 * exec_rotl - executes the rotl instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_rotl(stack_t** stack, unsigned int line_number);

/**
 * exec_rotr - executes the rotr instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_rotr(stack_t** stack, unsigned int line_number);

/**
 * exec_stack - executes the stack instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_stack(stack_t** stack, unsigned int line_number);

/**
 * exec_queue - executes the queue instruction
 * 
 * @stack: pointer to the stack
 * @line_number: the line number of the instruction
 * 
*/
void exec_queue(stack_t** stack, unsigned int line_number);

/**
 * free_stack - removes all elements from the stack
 * 
 * @stack: pointer to the stack
 * 
*/
void free_stack(stack_t** stack);


/**
 * get_word_count - counts the number of words in a string,
 * where a word is a contiguous substring of non-whitespace
 * characters
 * 
 * @str: the input string
 * 
 * Return - the number of words in the string
*/
int get_word_count(char* str);

/**
 * split_string - splits a string on whitespaces
 * 
 * @str: the string to split
 * 
 * Return - pointer to an array containing the split string
*/
char** split_string(char* str);

/**
 * substring - extracts a substring from the given string
 * 
 * @str: the original string
 * @from: the starting index of the substring
 * @to: the last index of the substring
 * 
 * Return - a newly allocated string str[from, to]
*/
char* substring(char* src, int from, int to);

/**
 * free_string_array - deallocates a dynamically-allocated
 * string array
 * 
 * @string_array: the string array to deallocate
*/
void free_string_array(char** string_array);

/**
 * is_valid_integer - checks if a string is covertible to integer
 * 
 * @str: the input string
 * 
 * Return - true if @str is convertible to integer, false otherwise
*/
bool is_valid_integer(char* str);

/**
 * remove_comments - Removes comments from a string by replacing the
 *                   first '#' with '\0'
 * 
 * @str: the input string
 * 
*/
void remove_comments(char* str);

/**
 * is_printable_ascii_char - Checks whether @ch is a printable ASCII
 *                           character
 * 
 * @ch: the input character's ASCII code
 * 
 * Return - true if @ch is a printable ASCII character, false
 *          otherwise
*/
bool is_printable_ascii_char(int ch);

#endif
