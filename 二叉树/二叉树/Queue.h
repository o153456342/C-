#pragma once

//队列先进先出FIFO
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct BinaryTreeNode;

typedef	struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

//队尾入
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);//头删
QDataType QueueFront(Queue* pq);//头读
QDataType QueueBack(Queue* pq);//尾读
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);