#ifndef STACK_H
#define STACK_H

/*
 * defining the data type and MAX size in the heaer file makes the code more
 * dynamic if we want to change the size of the stack, we only need to change
 * the STACK_SIZE and if we want to change the data type, we only need to change
 * the d_type here in the header file
 */

#define STACK_SIZE 10
typedef int d_type;

/**
 * this is a stack structure
 * it contains: top, elements
 * where top is the index of the element at the top of the stack
 * and elements is an array that stores the stack elements
 */

typedef struct
{
	int top;
	d_type elements[STACK_SIZE];
} stack;

void create_stack(stack *stk);
int is_empty(stack stk);
// checks if the stack is empty
// returns 1 if it's empty and 0 otherwise

int is_full(stack stk);
// checks if the stack is full
// returns 1 if it's full and 0 otherwise

d_type pop(stack *stk);
// deletes the element at the top of the stack
// and returns the deleted element

void void_pop(d_type *element, stack *stk);
// this is another implementation of the pop function

void push(stack *stk, d_type element);
// adds an element to the top of the stack

d_type peek(stack stk);
// returns the element at the top of the stack without deleting it

#endif
