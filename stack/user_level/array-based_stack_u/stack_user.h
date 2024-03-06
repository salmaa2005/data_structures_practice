#ifndef STACK_USER_H
#define STACK_USER_H

// These are the allowed functions for the user
//(USER LEVEL)

#define STACK_SIZE 10
typedef int d_type;

typedef struct
{
	int top;
	d_type elements[STACK_SIZE];
} stack;

void create_stack(stack *stk);
int is_empty(stack stk);
int is_full(stack stk);
d_type pop(stack *stk);
void void_pop(d_type *element, stack *stk);
void push(stack *stk, d_type element);
d_type stack_top(stack stk);

#endif
