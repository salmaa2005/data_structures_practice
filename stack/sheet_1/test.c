#include "stack.h"
#include <stdio.h>

int main(void)
{
	stack stk;
	create_stack(&stk);
	if (!is_full(stk))
		push(&stk, 1);
	if (!is_full(stk))
		push(&stk, 2);
	menu(&stk);
}
