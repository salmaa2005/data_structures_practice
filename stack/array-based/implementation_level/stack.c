#include "stack.h"

void createStack(Stack *stk)
{
	stk->top = 0;
}

int is_empty(Stack *stk)
{
	return stk->top == 0;
	// return !stk->top;
}

int is_full(Stack *stk)
{
	return stk->top >= STACK_SIZE;
}

int stack_size(Stack *stk)
{
	return stk->top;
}

void push(StackEntry e, Stack *stk)
{
	stk->items[stk->top++] = e;
	// add the element to the current position then increment
}
void pop(StackEntry *e, Stack *stk)
{
	*e = stk->items[--stk->top];
}

void stackTop(StackEntry *e, Stack *stk)
{
	*e = stk->items[stk->top - 1];
	// bnktbha kda 34an nseeb el top zy ma hoa bs n access el element el a5eer
}

void traverse(Stack *stk, void (*pf)(StackEntry))
{
	for (int i = stk->top - 1; i >= 0; i--)
	{
		(*pf)(stk->items[i]);
	}
}

void destroy(Stack *stk)
{
	stk->top = 0;
}
