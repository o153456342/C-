#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct TreeNode {
int val;
struct TreeNode* left;
struct TreeNode* right;

};


struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    struct TreeNode** que1 = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10001);
    struct TreeNode** que2 = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10001);
    int head = 0;
    int tail = 0;
    que1[tail] = root1;
    que2[tail] = root2;
    tail++;
    root1->val += root2->val;
    while (head < tail)
    {
        struct TreeNode* node1 = que1[head];
        struct TreeNode* node2 = que2[head];
        head++;
        if (node1->left && node2->left)
        {
            node1->left->val += node2->left->val;
            que1[tail] = node1->left;
            que2[tail] = node2->left;
            tail++;
        }
        else
        {
            if (!node1->left)
            {
                node1->left = node2->left;
            }
        }


        if (node1->right && node2->right)
        {
            node1->right->val += node2->right->val;
            que1[tail] = node1->right;
            que2[tail] = node2->right;
            tail++;
        }
        else
        {
            if (!node1->right)
            {
                node1->right = node2->right;
            }
        }
    }
    return root1;

}

int main()
{
	struct TreeNode* A = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	A->val = 1;
	A->left = NULL;
	A->right = NULL;

	struct TreeNode* B = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	B->val = 3;
	B->left = NULL;
	B->right = NULL;

	struct TreeNode* C = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	C->val = 2;
	C->left = NULL;
	C->right = NULL;

	struct TreeNode* D = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	D->val = 5;
	D->left = NULL;
	D->right = NULL;

    A->left = B;
    A->right = C;
    B->left = D;


	struct TreeNode* E = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	E->val = 2;
	E->left = NULL;
	E->right = NULL;

	struct TreeNode* F = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	F->val = 1;
	F->left = NULL;
	F->right = NULL;

	struct TreeNode* G = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	G->val = 3;
	G->left = NULL;
	G->right = NULL;

    struct TreeNode* H = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    H->val = 4;
    H->left = NULL;
    H->right = NULL;

    struct TreeNode* I = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    I->val = 5;
    I->left = NULL;
    I->right = NULL;

    E->left = F;
    E->right = G;
    F->right = H;
    G->right = I;

    
	
    mergeTrees(A,E);

	return 0;
}
