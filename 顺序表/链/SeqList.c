#include "SeqList.h"

void SeqListInit(SL* s)
{
	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;

	s->a =(SLDataTypt *) malloc(sizeof(SLDataTypt) * 4);
	if (s->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	s->size = 0;
	s->capacity = 4;
}

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataTypt x)
{
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListPushInsert(ps, ps->size, x);
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataTypt*)realloc(ps->a, sizeof(SLDataTypt) * (ps->capacity));

	}
	if (ps->a == NULL)
	{
		printf("扩容失败\n");
		exit(-1);
	}
}
void SeqListPopBack(SL* ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0; 
	// 通常删除数据只是找不到，但是东西还在，如果再继续写入，将会自动覆盖
	ps->size--;
}
void SeqListPushFront(SL* ps, SLDataTypt x)
{
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//int end = ps->size - 1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SeqListPushInsert(ps, 0, x);
}
void SeqListPopFront(SL* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
	SeqListErase(ps, 0);
}
//任意位置的插入删除
void SeqListPushInsert(SL* ps, int pos, SLDataTypt x)
{
	assert(ps);
	assert(pos <=  ps->size && pos >= 0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
	
//查找
int SeqListFine(SL* ps, SLDataTypt x)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		if (ps->a[start] == x)
			return start;
		++start;
	}

}
// 排序
void SeqListSort(SL* ps, SLDataTypt x);
//二分查找
void SeqListBinaryFind(SL* ps, SLDataTypt x);