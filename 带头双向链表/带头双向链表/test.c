#include "List.h"

void ListTest1()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	ListPushFront(phead, 4);
	ListPushFront(phead, 3);
	ListPushFront(phead, 2);
	ListPushFront(phead, 1);
	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListDestory(&phead);

}

void ListTest2()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);
	
	ListNode* pos = ListFind(phead, 3);
	ListInsert(pos, 30);
	ListPrint(phead);
	ListEarse(pos);
	ListPrint(phead);

	ListDestory(&phead);
}

int main()
{
	ListTest1();
	//ListTest2();
	return 0;
}