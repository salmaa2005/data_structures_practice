#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 5
typedef char stack_entry;

typedef struct
{
	int top;
	stack_entry elements[STACK_SIZE];
} stack;

void create_stack(stack *stk);
int is_empty(stack stk);
int is_full(stack stk);
stack_entry pop(stack *stk);
void void_pop(stack_entry *element, stack *stk);
void push(stack *stk, stack_entry element);
stack_entry peek(stack stk);
int stack_size(stack stk);
void menu(stack *stk);
void display_stack(stack *stk);

#endif
