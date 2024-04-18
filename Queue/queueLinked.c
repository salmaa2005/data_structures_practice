#include "queueLinked.h"
#include <stdlib.h>

void CreateQueue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->size = 0;
}
int QueueEmpty(Queue *pq)
{
	return pq->size == 0;
}
int QueueFull(Queue *pq)
{
	return 0;
}
void Enqueue(Queue *pq, QueueEntry e)
{
	QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
	pn->entry = e;
	pn->next = NULL;
	if (!pq->front)
	{
		pq->front = pq->rear = pn;
		pq->size++;
		return;
	}
	pq->rear->next = pn;
	pq->rear = pn;
	pq->size++;
}
void Dequeue(Queue *pq, QueueEntry *pe)
{
	QueueNode *pn = pq->front;
	*pe = pn->entry;
	if (pq->front == pq->rear)
	{
		pq->front = pq->rear = NULL;
		free(pn);
		pq->size--;
		return;
	}
	pq->front = pn->next;
	free(pn);
	pq->size--;
}
//==============================================================
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
	QueueNode *pn = pq->front;
	while (pn)
	{
		(*pf)(pn->entry);
		pn = pn->next;
	}
}
void SwapFrontRear(Queue *pq)
{
	if (pq->front != pq->rear)
	{
		QueueNode *pn = pq->front;
		while (pn->next->next != NULL)
			pn = pn->next;
		pq->rear->next = pq->front->next;
		pq->front->next = NULL;
		pn->next = pq->front;
		pn = pq->rear;
		pq->rear = pq->front;
		pq->front = pn;
	}
}
void AppendQueue(Queue *pq1, Queue *pq2)
{
	QueueNode *pn = pq2->front;
	while (pn)
	{
		QueueNode *N = (QueueNode *)malloc(sizeof(QueueNode));
		N->entry = pn->entry;
		N->next = NULL;
		pq1->rear->next = N;
		pq1->rear = N;
		pn = pn->next;
		pq1->size++;
	}
}
void ClearQueue(Queue *pq)
{
	while (pq->front)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}
