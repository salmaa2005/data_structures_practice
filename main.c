// test cases
#include "dlist.h"
int main()
{
	DList l;
	createDList(&l);
	traverse(&l, printNodeInfo);
	insert(&l, 1, "yarab");
	insert(&l, 3, "3alena");
	insert(&l, 4, "ba2a");
	insert(&l, 2, "toob");
	traverse(&l, printNodeInfo);
	doubleLinkedEntry e[100];
	deleteFromDList(&l, 2, e);
}
