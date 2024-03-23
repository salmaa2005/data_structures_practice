#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define STACK_SIZE 5
typedef int StackEntry;

typedef struct stack
{
	int top;
	StackEntry items[STACK_SIZE];
} Stack;

void createStack(Stack *stk);
int is_empty(Stack *stk);
int is_full(Stack *stk);
int stack_size(Stack *stk);
void push(StackEntry e, Stack *stk);
void pop(StackEntry *e, Stack *stk);
void stackTop(StackEntry *e, Stack *stk);
void traverse(Stack *stk, void (*pf)(StackEntry));
void destroy(Stack *stk);

#endif
