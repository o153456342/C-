#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;

ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);

ListNode* ListInit();
void ListClear(ListNode* phead);
void ListDestory(ListNode** pphead);

void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);

void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListEarse(ListNode* pos);