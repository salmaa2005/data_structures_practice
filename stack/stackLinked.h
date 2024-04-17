#ifndef STACKLINKED_H_INCLUDED
#define STACKLINKED_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int StackEntry;

typedef struct stacknode
{
	StackEntry entry;
	struct stacknode *next;
} StackNode;

typedef struct
{
	StackNode *top;
} Stack;

void CreateStack(Stack *ps);
int StackEmpty(Stack *ps);
int StackFull(Stack *ps);
void Push(Stack *ps, StackEntry e);
void Pop(Stack *ps, StackEntry *pe);
//============================================
void TraverseStack(Stack *ps, void (*pf)(StackEntry));
int StackSize(Stack *ps);
void DestroyStack(Stack *ps);
void PopFirst(Stack *ps, StackEntry *pe);
void StackCopy(Stack *ps1, Stack *ps2);

#endif
