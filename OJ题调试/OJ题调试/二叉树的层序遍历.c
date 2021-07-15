//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <assert.h>
//
//
//
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
//
//typedef	struct TreeNode* QDataType;
//
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//}Queue;
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//}
//
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//	pq->head = pq->tail = NULL;
//}
//
////��β��
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newnode->next = NULL;
//	newnode->data = x;
//
//	if (pq->tail == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
////��ͷ��
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->tail);
//
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head);
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head);
//
//	return pq->tail->data;
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	int size = 0;
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		cur = cur->next;
//		size++;
//	}
//
//	return size;
//}
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL;
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#define MAX_SIZE 10000
//
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//	*returnSize = 0;
//	if (root == NULL)
//	{
//		return NULL;
//	}
//
//	Queue q;
//	QueueInit(&q);
//	/* �������� */
//	int** res = (int**)malloc(sizeof(int*) * MAX_SIZE);
//	/* ��������ÿһ�еĸ��� */
//	*returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);
//
//	if (root)
//		QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		int k = 0;
//		QNode* rear = q.tail;
//		 /* ��ǰ�㷵������ĸ��� */
//		res[*returnSize] = (int*)malloc(sizeof(int) * ((q.head - q.tail)+1));
//		while (q.head > rear)
//		{
//			struct TreeNode* front = QueueFront(&q);
//			QueuePop(&q);
//
//			res[*returnSize][k++] = front->val;
//
//			if (front->left)
//			{
//				QueuePush(&q, front->left);
//			}
//
//			if (front->right)
//			{
//				QueuePush(&q, front->right);
//			}
//		}
//		(*returnColumnSizes)[*returnSize] = k;
//		(*returnSize)++;
//	}
//	QueueDestory(&q);
//	return res;
//}
//
//
//int main()
//{
//	struct TreeNode* A = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	A->val = 3;
//	A->left = NULL;
//	A->right = NULL;
//
//	struct TreeNode* B = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	B->val = 9;
//	B->left = NULL;
//	B->right = NULL;
//
//	struct TreeNode* C = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	C->val = 20;
//	C->left = NULL;
//	C->right = NULL;
//
//	struct TreeNode* D = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	D->val = 15;
//	D->left = NULL;
//	D->right = NULL;
//
//	struct TreeNode* E = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	E->val = 7;
//	E->left = NULL;
//	E->right = NULL;
//
//	A->left = B;
//	A->right = C;
//	C->left = D;
//	C->right = E;
//
//	struct TreeNode* root=A;
//	int returnSize=0;
//	int* returnColumnSize=0;
//	
//	levelOrder(root, &returnSize, &returnColumnSize);
//}
//
//// 
////
////
//// /**
////  * Return an array of arrays of size *returnSize.
////  * The sizes of the arrays are returned as *returnColumnSizes array.
////  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
////  */
////#define MAX_SIZE 10000
////int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
////    /* ���� */
////    *returnSize = 0;
////    if (root == NULL) {
////        return NULL;
////    }
////
////    /* ���� */
////    struct TreeNode* queue[MAX_SIZE];
////    /* �������� */
////    int** res = (int**)malloc(sizeof(int*) * MAX_SIZE);
////    /* ��������ÿһ�еĸ��� */
////    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);
////    /* ���е�ͷβָ�� */
////    int head = 0, rear = 0;
////    /* �����ڵ������ */
////    queue[rear++] = root;
////    /* ѭ������������нڵ� */
////    while (head != rear) {
////        /* ��¼��ǰ���β�ڵ� */
////        int preRear = rear;
////        /* ��ǰ��Ľڵ����� */
////        int k = 0;
////        /* ��ǰ�㷵������ĸ��� */
////        res[*returnSize] = (int*)malloc(sizeof(int) * (preRear - head));
////        /* ���α�����ǰ��ڵ� */
////        while (head < preRear) {
////            /* ���� */
////            struct TreeNode* p = queue[head];
////            /* ���·��������е�ֵ */
////            res[*returnSize][k++] = p->val;
////            /* ����ǰ���ӽ������ҽڵ���� */
////            if (p->left) {
////                queue[rear++] = p->left;
////            }
////            if (p->right) {
////                queue[rear++] = p->right;
////            }
////            /* ����ͷ�������ƶ�һλ */
////            head++;
////        }
////        /* ���·������鱾��ڵ���� */
////        (*returnColumnSizes)[*returnSize] = k;
////        (*returnSize)++;
////    }
////    return res;
////}