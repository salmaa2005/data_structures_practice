#include "stackArray.h"
#include <stdio.h>
void Display(StackEntry e)
{
	printf("\n%d", e);
}
int size2(Stack *s)
{
	Stack stk;
	createStack(&stk);
	int ctr = 0;
	StackEntry e;
	while (!isEmpty(s))
	{
		pop(s, &e);
		push(&stk, e);
		ctr++;
	}
	while (!isEmpty(&stk))
	{
		pop(&stk, &e);
		push(s, e);
	}
	return ctr;
}
void copyTop2(Stack *s, StackEntry *e)
{
	pop(s, e);
	push(s, *e);
}
void CopyFirst2(Stack *s, StackEntry *e)
{
	StackEntry temp;
	Stack stk;
	createStack(&stk);
	while (!isEmpty(s))
	{
		pop(s, e);
		push(&stk, *e);
	}
	pop(&stk, &temp);
	push(&stk, temp);
	while (!isEmpty(&stk))
	{
		pop(&stk, e);
		push(s, *e);
	}
	*e = temp;
}

int main()
{
	StackEntry e;
	Stack s;
	createStack(&s);
	Traverse(&s, &Display);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	Traverse(&s, &Display);
	StackEntry pe;
	pop(&s, &pe);
	Traverse(&s, &Display);

	printf("\nSize = %d\n", size2(&s));
	copyTop2(&s, &e);
	printf("\nTop = %d\n", e);
	CopyFirst2(&s, &e);
	printf("\nFirst = %d\n", e);
	popFirst(&s, &e);
	printf("\nPop First = %d\n", e);
	Traverse(&s, &Display);

	return 0;
}
