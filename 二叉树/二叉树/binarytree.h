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

//		深度优先遍历(递归的方法)
//前序
void PrevOrder(BTNode* root);
//中序
void InOrder(BTNode* root);
//后序
void PostOrder(BTNode* root);
//计算节点个数
int TreeSize(BTNode* root);
//计算叶子个数
int TreeLeafSize(BTNode* root);

//		广度优先遍历(队列的方法)
void LevelOrder(BTNode* root);
