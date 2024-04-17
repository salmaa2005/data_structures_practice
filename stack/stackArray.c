#include "stackArray.h"

void createStack(Stack *ps)
{
	ps->top = -1;
}
int isFull(Stack *ps)
{
	return (ps->top == STACK_SIZE - 1);
}
int isEmpty(Stack *ps)
{
	return (ps->top == -1);
}
void push(Stack *ps, StackEntry e)
{
	ps->entry[++(ps->top)] = e;
}
void pop(Stack *ps, StackEntry *pe)
{
	*pe = ps->entry[ps->top--];
}

// _______________________________________________________

void Traverse(Stack *ps, void (*pf)(StackEntry))
{
	for (int i = ps->top; i >= 0; i--)
		(*pf)(ps->entry[i]);
}
int size(Stack *ps)
{
	return ps->top + 1;
}
void copyTop(Stack *ps, StackEntry *pe)
{
	*pe = ps->entry[ps->top];
}
void copyFirst(Stack *ps, StackEntry *pe)
{
	*pe = ps->entry[0];
}
void popFirst(Stack *ps, StackEntry *pe)
{
	*pe = ps->entry[0];
	for (int i = 1; i <= ps->top; i++)
		ps->entry[i - 1] = ps->entry[i];
	ps->top--;
}
