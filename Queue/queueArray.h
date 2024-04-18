#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#define MAX_QUEUE 5
typedef int QueueEntry;
typedef struct
{
	int front, rear, size;
	QueueEntry entry[MAX_QUEUE];
} Queue;

void CreateQueue(Queue *pq);
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
void Append(Queue *pq, QueueEntry e);
void Serve(Queue *pq, QueueEntry *pe);
//===================================================
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));
void DestroyQueue(Queue *pq);
void CopyQueue(Queue *pq1, Queue *pq2);
void ServeLast(Queue *pq, QueueEntry *pe);
void ReverseQueue(Queue *pq);

#endif
