#include "stackLinked.h"

void DisplayLinked(StackEntry e)
{
	printf("\n%d\n", e);
}

int main()
{
	StackEntry e;
	Stack s, s2;
	CreateStack(&s);
	CreateStack(&s2);

	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	Push(&s, 5);

	// StackCopy(&s, &s2);

	printf("\nSize = %d\n", StackSize(&s));
	PopFirst(&s, &e);
	DisplayLinked(e);
	printf("\nSrack s1\n");
	TraverseStack(&s, &DisplayLinked);

	printf("\nSrack s2\n");
	TraverseStack(&s2, &DisplayLinked);

	return 0;
}
