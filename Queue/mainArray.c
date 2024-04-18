#include "queueArray.h"
#include <stdio.h>

void Display(QueueEntry e)
{
	printf("\n%d\n", e);
}

void ServeLast2(Queue *pq, QueueEntry *pe)
{
	int size = 0;
	QueueEntry e;
	Queue tmp;
	CreateQueue(&tmp);

	while (!QueueEmpty(pq))
	{
		Serve(pq, &e);
		Append(&tmp, e);
		size++;
	}
	//    for(int i = 0 ; i < size -1 ; i++)
	while (size > 1)
	{
		Serve(&tmp, &e);
		Append(pq, e);
		size--;
	}
}

void CopyQueue2(Queue *q1, Queue *q2)
{
	Queue temp;
	CreateQueue(&temp);
	QueueEntry e;
	while (!QueueEmpty(q1))
	{
		Serve(q1, &e);
		Append(&temp, e);
	}
	while (!QueueEmpty(&temp))
	{
		Serve(&temp, &e);
		Append(q2, e);
		Append(q1, e);
	}
}
int main()
{
	QueueEntry e;
	Queue q;
	CreateQueue(&q);

	Append(&q, 1);
	Append(&q, 2);
	Append(&q, 3);
	Append(&q, 4);
	Append(&q, 5);

	//	ReverseQueue(&q);

	TraverseQueue(&q, &Display);

	return 0;
}
