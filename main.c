// test cases
#include "dlist.h"
int main()
{
	DList l;
	createDList(&l);
	traverse(&l, printNodeInfo);
	doubleLinkedEntry e[100];
	Info info[] = {{-1, "A"}, {2, "B"}, {3, "C"}, {4, "D"},
				   {5, "E"},  {6, "F"}, {7, "G"}};
	insert(&l, info[1]);
	insert(&l, info[0]);
	insert(&l, info[5]);
	insert(&l, info[4]);
	insert(&l, info[3]);
	insert(&l, info[6]);
	insert(&l, info[2]);
	deleteFromDList(&l, 8, e);
	deleteFromDList(&l, 0, e);
	deleteFromDList(&l, 3, e);
	insert(&l, info[0]);
	traverse(&l, printNodeInfo);
}
