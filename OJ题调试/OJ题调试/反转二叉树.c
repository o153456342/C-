//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <assert.h>
//
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
// 
//#define MAX_INT 10000
//
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//    if (!root)
//        return NULL;
//
//    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_INT);
//    int topi = 0;
//    stack[topi++] = root;
//    while (topi)
//    {
//        struct TreeNode* top = stack[--topi];
//        struct TreeNode* tmp = top->left;
//        top->left = top->right;
//        top->right = tmp;
//
//        if (top->right)
//        {
//            stack[topi++] = top->right;
//        }
//        if (top->left)
//        {
//            stack[topi++] = top->left;
//        }
//    }
//    return root;
//}
//
//
//int main()
//{
//	struct TreeNode* A = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	A->val = 4;
//	A->left = NULL;
//	A->right = NULL;
//
//	struct TreeNode* B = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	B->val = 2;
//	B->left = NULL;
//	B->right = NULL;
//
//	struct TreeNode* C = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	C->val = 7;
//	C->left = NULL;
//	C->right = NULL;
//
//	struct TreeNode* D = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	D->val = 1;
//	D->left = NULL;
//	D->right = NULL;
//
//	struct TreeNode* E = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	E->val = 3;
//	E->left = NULL;
//	E->right = NULL;
//
//	struct TreeNode* F = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	F->val = 6;
//	F->left = NULL;
//	F->right = NULL;
//
//	struct TreeNode* G = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	G->val = 9;
//	G->left = NULL;
//	G->right = NULL;
//
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//	C->left = F;
//	C->right = G;
//
//	struct TreeNode* root=A;
//	
//	invertTree(root);
//
//	return 0;
//}
