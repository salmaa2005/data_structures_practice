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

// return -1 if allocation failed
// returns 1 if successful
void insert(DList *pdl, int pos, doubleLinkedEntry e[])
{
	Node *pn = (Node *)malloc(sizeof(Node));
	pn->info.Key = pos;
	Node *trav = pdl->head;
	if (pdl->head == NULL)
	{
		pdl->head = pn;
		pdl->tail = pn;
		pn->next = NULL;
		pn->prev = NULL;
		pdl->size++;
		return;
	}
	while (trav != NULL && trav->info.Key < pos)
		trav = trav->next;
	for (int i = 0; trav->info.entry[i] != '\0'; i++)
		pn->info.entry[i] = e[i];
	if (trav->prev == NULL)
	{
		trav->prev = pn;
		pn->next = trav;
		pn->prev = NULL;
		pdl->head = pn;
	}
	if (trav->next == NULL && trav->info.Key < pn->info.Key)
	{
		trav->next = pn;
		pn->prev = trav;
		pdl->tail = pn;
		pn->next = NULL;
	}
	else
	{
		trav->prev->next = pn;
		pn->next = trav;
		pn->prev = trav->prev;
		trav->prev = pn;
	}

	pdl->size++;
}

// returns -1 if list is empty
// returns 0 if position is out of bounds
// returns 1 if element is deleted successfully
int deleteFromDList(DList *pdl, int pos, doubleLinkedEntry pe[])
{
	if (pdl->head == NULL)
		return -1;
	if (pos < 0 || pos > pdl->tail->info.Key)
		return 0;
	Node *trav = pdl->head;
	for (int i = 0; pe[i] != '\0'; i++)
		pe[i] = trav->info.entry[i];
	trav = pdl->head;
	while (trav->info.Key < pos)
		trav = trav->next;
	if (trav->prev == NULL)
	{
		pdl->head = trav->next;
		pdl->head->prev = NULL;
	}
	else if (trav->next == NULL)
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
	if (pdl->head == NULL)
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

// Additional functions
void printNodeInfo(Info info)
{
	printf("Key: %d\n", info.Key);
	printf("Entry: %s\n", info.entry);
}
