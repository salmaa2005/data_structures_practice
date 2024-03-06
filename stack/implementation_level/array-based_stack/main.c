#include "stack.h"
#include <stdio.h>

int main(void)
{
	stack s;
	create_stack(&s);
	if (is_empty(s))
		printf("Stack is empty\n");
	push(&s, 1);
	if (!is_empty(s))
		printf("Stack is not empty\n");
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	push(&s, 6);
	push(&s, 7);
	push(&s, 8);
	push(&s, 9);

	if (!is_full(s))
		printf("Stack is not full\n");

	push(&s, 10);

	if (is_full(s))
		printf("Stack is full\n");

	printf("Top element: %d\n", peek(s));
	for (int i = 0; i < STACK_SIZE; i++)
	{
		printf("Element %d: %d\n", i + 1, pop(&s));
	}

	if (is_empty(s))
		printf("finally the Stack is empty :3 \n");
}
