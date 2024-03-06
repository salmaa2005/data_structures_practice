#include "stack.h"
#include <stdio.h>

/**
 * matensa4 t3adel el d_type t5aleeh char fe stack.h
 */
int main(void)
{
	stack stk;
	create_stack(&stk);
	char c;
	printf("Type the word and press enter to exit: ");
	while (!is_full(stk) && c != '\n')
	{
		scanf("%c", &c);
		push(&stk, c);
	}
	while (!is_empty(stk))
		printf("%c", pop(&stk));
}
