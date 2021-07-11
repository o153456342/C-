#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

void DestoryTree(BTNode* root);

//		������ȱ���(�ݹ�ķ���)
//ǰ��
void PrevOrder(BTNode* root);
//����
void InOrder(BTNode* root);
//����
void PostOrder(BTNode* root);
//����ڵ����
int TreeSize(BTNode* root);
//����Ҷ�Ӹ���
int TreeLeafSize(BTNode* root);

//		������ȱ���(���еķ���)
void LevelOrder(BTNode* root);
