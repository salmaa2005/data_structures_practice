#include "queueArray.h"

void CreateQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}
int QueueEmpty(Queue *pq)
{
	return (pq->size == 0);
}
int QueueFull(Queue *pq)
{
	return (pq->size == MAX_QUEUE);
}
void Append(Queue *pq, QueueEntry e)
{
	pq->rear = (pq->rear + 1) % MAX_QUEUE;
	pq->entry[pq->rear] = e;
	pq->size++;
}
void Serve(Queue *pq, QueueEntry *pe)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MAX_QUEUE;
	pq->size--;
}
//===================================================
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
	for (int i = pq->front, s = 0; s < pq->size; i = (i + 1) % MAX_QUEUE, s++)
		(*pf)(pq->entry[i]);
}
void DestroyQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}
void CopyQueue(Queue *pq1, Queue *pq2)
{
	for (int i = 0; i <= pq1->rear; i = (i + 1) % MAX_QUEUE)
		pq2->entry[i] = pq1->entry[i];
}
void ServeLast(Queue *pq, QueueEntry *pe)
{
	*pe = pq->entry[pq->rear];
	pq->rear = (pq->rear - 1) % MAX_QUEUE;
	pq->size--;
}
void ReverseQueue(Queue *pq)
{
	for (int i = pq->front, j = pq->rear; i <= pq->rear / 2;
		 i = (i + 1) % MAX_QUEUE, j = (j - 1) % MAX_QUEUE)
	{
		QueueEntry temp = pq->entry[i];
		temp = pq->entry[i];
		pq->entry[i] = pq->entry[j];
		pq->entry[j] = temp;
	}
}
