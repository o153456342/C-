#include "slist.h"

int main()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPushFront(&pList, 0);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
	SListNode* pos = SListSearch(pList, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(pList);
	return 0;
}