#include "stack.h"
#include <stddef.h>
#include <stdio.h>

void create_stack(stack *stk)
{
	stk->top = -1;
	// (*stk).top = -1;
}

/**
 * precondition: stack must be created.
 * postcondition: stack remains unchanged and the function returns 1 if the
 * stack is empty returns 0 otherwise
 */
int is_empty(stack stk)
{
	if (stk.top == -1)
		return 1;
	return 0;
}

/**
 * precondition: stack must be created.
 * postcondition: stack remains unchanged
 * the function returns 1 if the stack is full and returns 0 otherwise
 */
int is_full(stack stk)
{
	if (stk.top == STACK_SIZE - 1)
		return 1;
	return 0;
}

/**
 * precondition: stack must be created and not full.
 * postcondition: a new element is added to the top of the stack
 */
void push(stack *stk, stack_entry element)
{
	stk->top++;
	stk->elements[stk->top] = element;
}

stack_entry pop(stack *stk)
{
	return (stk->elements[stk->top--]);
}

void void_pop(stack_entry *element, stack *stk)
{
	*element = stk->elements[stk->top--];
}

/**
 * precondition: stack must be created and not empty.
 * postcondition: stack remains unchanged
 */
stack_entry stack_top(stack stk)
{
	int top_e;
	top_e = pop(&stk);
	push(&stk, top_e);
	return top_e;
}

int stack_size(stack stk)
{
	return stk.top + 1;
}

void menu(stack *stk)
{
	char item;
	int choice;

	printf("1. To Push\n2. To Pop\n3. To Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
			printf("Enter an item to push: ");
			scanf("%c", &item);
			if (!is_full(*stk))
				push(&stk, item);
			else
				printf("Stack is full\n");
			break;

		case 2:
			if (!is_empty(*stk))
			{
				stack_entry top_e = pop(stk); // Remove the & before stk
				printf("Item popped: %c\n", top_e);
			}
			else
			{
				printf("Stack is empty\n");
			}
			break;

		case 3:
			printf("Exiting...\n");
			break;
	}
}

void display_stack(stack *stk)
{
	stack stk2;
	create_stack(&stk2);
	while (!is_empty(*stk))
	{
		stack_entry top_e = pop(stk);
		push(&stk2, top_e);
		printf("%c\n", top_e);
	}

	while (!is_empty(stk2))
	{
		stack_entry top_e = pop(&stk2);
		push(stk, top_e);
	}
}
