#ifndef QUEUELINKED_H_INCLUDED
#define QUEUELINKED_H_INCLUDED

typedef int QueueEntry;

typedef struct queuenode
{
	QueueEntry entry;
	struct queuenode *next;
} QueueNode;

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
	int size;
} Queue;

void CreateQueue(Queue *pq);
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
void Enqueue(Queue *pq, QueueEntry e);
void Dequeue(Queue *pq, QueueEntry *pe);
//==============================================================
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));
void SwapFrontRear(Queue *pq);
void AppendQueue(Queue *pq1, Queue *pq2);
void ClearQueue(Queue *pq);

#endif // QUEUELINKED_H_INCLUDED
