#ifndef _DLIST_H
#define _DLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char doubleLinkedEntry;

// struct created
typedef struct
{
	int Key;
	doubleLinkedEntry entry[100]; // specified size edited
} Info;

typedef struct node
{
	Info info;
	struct node *prev;
	struct node *next;
} Node;
typedef struct
{
	Node *head;
	Node *tail;
	int size;
} DList;
void createDList(DList *);
int DListFull(DList *);
int DListEmpty(DList *);
void insert(DList *pdl, int pos, doubleLinkedEntry e[]);
int deleteFromDList(DList *pdl, int pos,
					doubleLinkedEntry e[]);			 // return type edited
int deleteFirst(DList *pdl, doubleLinkedEntry pe[]); // return type edited
void traverse(DList *pdl, void (*pf)(Info)); // argument of the function changed

// Additional functions
void printNodeInfo(Info info);

#endif
