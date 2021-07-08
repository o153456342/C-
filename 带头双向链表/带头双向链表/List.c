#include "List.h"

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = x;

	return newNode;
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newNode = BuyListNode(x);
	//tail->next = newNode;
	//newNode->prev = tail;

	//newNode->next = phead;
	//phead->prev = newNode;

	ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);

	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;
	//
	//phead->prev = tailPrev;
	//tailPrev->next = phead;
	//free(tail);
	//tail = NULL;
	
	ListEarse(phead->prev);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	//assert(phead);

	//ListNode* first = phead->next;
	//ListNode* newNode = BuyListNode(x);

	//phead->next = newNode;
	//newNode->prev = phead;

	//first->prev = newNode;
	//newNode->next = first;

	ListInsert(phead->next, x);

}

void ListPopFront(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);

	//ListNode* first = phead->next;
	//ListNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);

	ListEarse(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* newNode = BuyListNode(x); 

	posPrev->next = newNode;
	newNode->prev = posPrev;

	newNode->next = pos;
	pos->prev = newNode;
}

void ListEarse(ListNode* pos)
{
	assert(pos);
	
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

void ListClear(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		phead->next = next;
		next->prev = phead;
		free(cur);
		cur = next;
	}
}

void ListDestory(ListNode** pphead)
{
	assert(*pphead);

	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}
