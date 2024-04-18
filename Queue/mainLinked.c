#include "queueLinked.h"
#include <stdio.h>
#include <stdlib.h>

void Display(QueueEntry e)
{
	printf("\n%d\n", e);
}
int main()
{
	Queue q, q2;
	CreateQueue(&q);
	CreateQueue(&q2);
	QueueEntry e;

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	Enqueue(&q2, 13);
	Enqueue(&q2, 14);
	Enqueue(&q2, 15);

	AppendQueue(&q, &q2);

	Dequeue(&q2, &e);

	TraverseQueue(&q, &Display);
	printf("\n==============================\n");
	TraverseQueue(&q2, &Display);

	return 0;
}
