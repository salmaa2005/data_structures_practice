#include "stack_imp.h"
#include <stdio.h>

/**
 * precondition: none
 * postcondition: stack is initialized to be empty
 *
 * stk->top: means that we'll initialize the top either with -1 or 0
 * -1 is preferred if we're implementing the stack using an array because index
 * -1 means there're no elements yet we're calling the stack by reference (using
 * a pointer) because we'll modify the stack itself
 */

void create_stack(stack *stk)
{
	stk->top = -1;
	// (*stk).top = -1;
}

/**
 * precondition: the stack is initialized
 * postcondition: returns 1 if the stack is empty and 0 otherwise
 *
 * here we'll pass the stack by reference because we'll not modify the stack
 * we'll only check the value of the top
 */
int is_empty(stack stk)
{
	if (stk.top == -1)
		// here stk is not passed by value so we'll use stk.top not stk->top
		return 1;
	return 0;
	// rerurn (stk.top == -1);
	// this evaluates what's inside the brackets and returns 1 if true and 0 if
	// false
}

/**
 * precondition: the stack is initialized
 * postcondition: returns 1 if the stack is full and 0 otherwise
 *
 * here we're not modifying anything so we'll pass the stack by value
 */
int is_full(stack stk)
{
	if (stk.top == STACK_SIZE - 1)
		return 1;
	return 0;
}

/**
 * precondition: the stack is initialized and is not full
 * postcondition: a new element is added to the top of the stack
 *
 * here we'll pass the stack by reference because we'll modify the stack
 */

void push(stack *stk, d_type element)
{
	stk->top++;
	stk->elements[stk->top] = element;
	/**
	 * another implemention:
	 * stk->elements[++stk->top] = element;
	 * lazem n7ot el ++ abl el stk->top 3a4an nzawed el top el awel w ba3den
	 * n7ot el value
	 * el afdal n3ml check 3al stack law full fel main m4 hena
	 */
}

/**
 * precondition: the stack is initialized and is not empty
 * postcondition: the top element of the stack is removed and returned
 *
 * here we'll pass the stack by reference because we'll modify the stack
 */

d_type pop(stack *stk)
{
	return (stk->elements[stk->top--]);
	// hena 3amalna -- ba3d el top 3a4an n3rf nraga3 el element el a5eer
	// w ba3den nn2s el top
	// el afdal n3ml check 3al stack law empty fel main m4 hena
}

void void_pop(d_type *element, stack *stk)
{
	if (stk->top == -1)
	{
		printf("ERROR: Stack underflow\n");
		return;
	}
	*element = stk->elements[stk->top--];
}

/**
 * precondition: the stack is initialized and is not empty
 * postcondition: the top element is returned and the stack remains unchanged
 *
 * we'll pass the stack by value because we'll not modify the stack
 */

d_type peek(stack stk)
{
	return (stk.elements[stk.top]);
	// you're only allowed to do this in the implementation level
	// on the user level you're only allowed to use push, pop, full, empty
	// you don't have access to the stack array
}
