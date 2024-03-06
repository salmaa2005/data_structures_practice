#include "stack_imp.h"
#include <stdio.h>

/**
 * here are some random test cases
 */
int main(void)
{
	stack s;
	create_stack(&s);
	if (is_empty(s))
		printf("Stack is empty\n");
	pop(&s);

	// lazem abl kol push tcheck en el stack not full
	// w abl kol pop tcheck el stack not empty
	push(&s, 1);
	if (!is_empty(s))
		printf("Stack is not empty\n");
	if (!is_full(s))
		push(&s, 2);
	if (!is_full(s))
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
	push(&s, 11);

	printf("Top element: %d\n", peek(s));
	for (int i = 0; i < STACK_SIZE; i++)
	{
		printf("Element %d: %d\n", i + 1, pop(&s));
	}

	if (is_empty(s))
		printf("finally the Stack is empty :3 \n");
}
