#include "stackLinked.h"
void CreateStack(Stack *ps)
{
	ps->top = NULL;
}
int StackEmpty(Stack *ps)
{
	return (!ps->top);
}
int StackFull(Stack *ps)
{
	return 0;
}
void Push(Stack *ps, StackEntry e)
{
	StackNode *pn;
	pn = (StackNode *)malloc(sizeof(StackNode));
	pn->entry = e;
	pn->next = ps->top;
	ps->top = pn;
}
void Pop(Stack *ps, StackEntry *pe)
{
	*pe = ps->top->entry;
	StackNode *pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
}
//============================================
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
	StackNode *current = ps->top;
	while (current)
	{
		(*pf)(current->entry);
		current = current->next;
	}
}
int StackSize(Stack *ps)
{
	int ctr = 0;
	StackNode *current = ps->top;
	while (current)
	{
		ctr++;
		current = current->next;
	}
	return ctr;
}
void DestroyStack(Stack *ps)
{
	StackNode *current = ps->top;
	while (current)
	{
		ps->top = ps->top->next;
		free(current);
		current = current->next;
	}
}
void PopFirst(Stack *ps, StackEntry *pe)
{
	if (!ps->top->next)
	{
		*pe = ps->top->entry;
		free(ps->top);
		ps->top = NULL;
		return;
	}
	StackNode *prev, *pn = ps->top;
	while (pn->next)
	{
		prev = pn;
		pn = pn->next;
	}
	*pe = pn->entry;
	prev->next = NULL;
	free(pn);
}
void StackCopy(Stack *ps1, Stack *ps2)
{
	StackNode *trav = ps1->top;
}
