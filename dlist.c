#include "dlist.h"

void createDList(DList *pdl)
{
	pdl->head = NULL;
}

int DListFull(DList *pdl)
{
	return 0;
}
int DListEmpty(DList *pdl)
{
	return pdl->head == NULL;
}

// returns -1 if allocation failed
// returns 0 when key is invalid
// returns 1 if successful
int insert(DList *pdl, Info info)
{
	Node *pn = (Node *)malloc(sizeof(Node));
	if (!pn || info.Key < 1)
		return 0;
	pn->info = info;
	if (!pdl->head)
	{
		pn->next = NULL;
		pn->prev = NULL;
		pdl->head = pn;
		pdl->tail = pn;
	}
	else
	{
		Node *trav = pdl->head;
		while (info.Key > trav->info.Key && trav->next)
			trav = trav->next;
		if (info.Key > trav->info.Key && !trav->next)
		{
			pn->next = NULL;
			pn->prev = trav;
			trav->next = pn;
			pdl->tail = pn;
		}
		else
		{
			pn->next = trav;
			pn->prev = trav->prev;
			if (pn->prev)
				trav->prev->next = pn;
			else
				pdl->head = pn;
		}
	}
	pdl->size++;
	return 1;
}

// returns -1 if list is empty
// returns 0 if position is out of bounds
// returns 1 if element is deleted successfully
int deleteFromDList(DList *pdl, int pos, doubleLinkedEntry pe[])
{
	if (pdl->head == NULL)
		return -1;
	if (pos < 0 || pos > pdl->tail->info.Key || pos < pdl->head->info.Key)
		return 0;
	Node *trav = pdl->head;
	for (int i = 0; pe[i] != '\0'; i++)
		pe[i] = trav->info.entry[i];
	trav = pdl->head;
	while (trav->info.Key < pos)
		trav = trav->next;
	if (!trav->prev)
	{
		pdl->head = trav->next;
		pdl->head->prev = NULL;
	}
	else if (!trav->next)
	{
		pdl->tail = trav->prev;
		pdl->tail->next = NULL;
	}
	else
	{
		trav->prev->next = trav->next;
		trav->next->prev = trav->prev;
	}
	free(trav);
	pdl->size--;
	return 1;
}

// returns -1 if list is empty
// returns 1 if element is deleted successfully
int deleteFirst(DList *pdl, doubleLinkedEntry pe[])
{
	if (!pdl->head)
		return -1;
	Node *trav = pdl->head;
	for (int i = 0; trav->info.entry[i] != '\0'; i++)
		pe[i] = trav->info.entry[i];
	trav = pdl->head;
	if (pdl->size == 1)
	{
		pdl->head = NULL;
		pdl->tail = NULL;
	}
	else
	{
		pdl->head = trav->next;
		pdl->head->prev = NULL;
	}
	free(trav);
	pdl->size--;
	return 1;
}
void traverse(DList *pdl, void (*pf)(Info))
{
	Node *trav = pdl->head;
	while (trav)
	{
		(*pf)(trav->info);
		trav = trav->next;
	}
}

// Additional functions:
void printNodeInfo(Info info)
{
	printf("Key: %d\n", info.Key);
	printf("Entry: %s\n", info.entry);
}

void displayDlist(DList *pdl)
{
	traverse(pdl, printNodeInfo);
}
