#include "stack.h"

void display(StackEntry e)
{
	printf("%d\n", e);
}
int main(void)
{
	Stack s;
	createStack(&s);

	if (is_empty(&s))
		printf("Stack is empty\n");

	push(1, &s);
	push(2, &s);
	if (is_empty(&s))
		printf("Stack is empty\n");

	push(3, &s);
	push(4, &s);
	push(5, &s);

	if (is_full(&s))
		printf("Stack is full\n");

	StackEntry e;
	pop(&e, &s);
	printf("%d\n", e);

	traverse(&s, &display);
}
