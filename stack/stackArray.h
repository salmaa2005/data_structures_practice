#ifndef STACKARRAY_H
#define STACKARRAY_H

#define STACK_SIZE 5

typedef int StackEntry;

typedef struct
{
	int top;
	StackEntry entry[STACK_SIZE];
} Stack;

void createStack(Stack *ps);
int isFull(Stack *ps);
int isEmpty(Stack *ps);
void push(Stack *ps, StackEntry e);
void pop(Stack *ps, StackEntry *pe);

// __________________________________________________

void Traverse(Stack *ps, void (*pf)(StackEntry));
int size(Stack *ps);
void copyTop(Stack *ps, StackEntry *pe);
void copyFirst(Stack *ps, StackEntry *pe);
void popFirst(Stack *ps, StackEntry *pe);

#endif
