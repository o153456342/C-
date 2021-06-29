#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//顺序表，有效数组在数组中必须连续
//静态顺序表设计（固定大小）
//动态顺序表设计（大小可变）
typedef int SLDataTypt;
#define N 10

typedef struct SeqList
{
	SLDataTypt* a;//指向动态开辟的数组
	int size;//有效数据个数
	int capacity;//容量
} SL,SeqList;

//尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataTypt x);
void SeqListPopBack( SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushFront( SL* ps , SLDataTypt x);
void SeqListPopFront( SL* ps);
//任意位置的插入删除
void SeqListPushInsert( SL* ps, int pos, SLDataTypt x);
void SeqListErase( SL* ps, int pos);
//查找
int SeqListFine(SL* ps, SLDataTypt x);
// 排序
void SeqListSort(SL* ps, SLDataTypt x);
//二分查找
void SeqListBinaryFind(SL* ps, SLDataTypt x);
//初始化
void SeqListInit(SL* ps);
//销毁动态开辟的空间
void SeqListDestroy(SL* ps);

void SeqListPrint(SL* ps);