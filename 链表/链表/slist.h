#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>		 

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);

void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

void SListPrint(SListNode* phead);
void SListSize(SListNode* phead);
SListNode* SListSearch(SListNode* phead, SListDataType x);