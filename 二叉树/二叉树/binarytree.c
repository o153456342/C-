#include "binarytree.h"
#include "Queue.h"

void DestoryTree(BTNode* root)
{
	if (root == NULL)
		return;

	DestoryTree(root->left);
	DestoryTree(root->right);

	free(root);
	root = NULL;
}

//Ç°Ðò
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//ÖÐÐò
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//ºóÐò
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	return (root->left == NULL && root->right == NULL) ? 1 : TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);

		}
	}

	printf("\n");

	QueueDestory(&q);
}