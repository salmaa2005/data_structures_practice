#include "stack_user.h"
#include <stdio.h>

// this is the user level so you're only allowed to use:
// push, pop, full, empty

int main(void)
{
	stack stk;
	create_stack(&stk);
	if (!is_full(stk))
		push(&stk, 1);

	if (!is_full(stk))
		push(&stk, 2);

	if (!is_full(stk))
		push(&stk, 3);

	if (!is_full(stk))
		push(&stk, 4);

	if (!is_full(stk))
		push(&stk, 5);

	//	if (!is_full(stk))
	//	push(&stk, 6);
	printf("%d\n", stack_top(stk));
}
