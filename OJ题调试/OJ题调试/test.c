#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

  //typedef struct TreeNode {
  //    int val;
  //    struct TreeNode *left;
  //   struct TreeNode *right;
  //}TNode;
 

  //int maxDepth(struct TreeNode* root)
  //{
  //    if (root == NULL)
  //        return 0;

  //    int leftmax = maxDepth(root->left);
  //    int rightmax = maxDepth(root->right);

  //    return leftmax > rightmax ? leftmax + 1 : rightmax + 1;

  //}

  //bool isBalanced(struct TreeNode* root)
  //{
  //    if (root == NULL)
  //        return true;

  //    int leftmax = maxDepth(root->left);
  //    int rightmax = maxDepth(root->right);

  //    if (abs(leftmax - rightmax) <= 1)
  //        return true;
  //    else
  //        return false;
  //}

//void PreOrder(struct TreeNode* root, int* ret, int* i)
//{
//    if (root == NULL)
//        return;
//
//    ret[(*i)] = root->val;
//    ++(*i);
//    PreOrder(root->left, ret, &i);
//    PreOrder(root->right, ret, &i);
//}
//
//int TreeSize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int size = TreeSize(root);
//    int* ret = (int*)malloc(size * sizeof(int));
//    int i = 0;
//    PreOrder(root, ret, &i);
//
//    *returnSize = TreeSize(root);
//    return ret;
//}

//int main()
//{
//    TNode* A = (TNode*)malloc(sizeof(TNode));
//    A->val = 1;
//    A->left = NULL;
//    A->right = NULL;
//
//    TNode* B = (TNode*)malloc(sizeof(TNode));
//    B->val = 2;
//    B->left = NULL;
//    B->right = NULL;
//
//    TNode* C = (TNode*)malloc(sizeof(TNode));
//    C->val = 3;
//    C->left = NULL;
//    C->right = NULL;
//
//    TNode* D = (TNode*)malloc(sizeof(TNode));
//    D->val = 3;
//    D->left = NULL;
//    D->right = NULL;
//
//    TNode* E = (TNode*)malloc(sizeof(TNode));
//    E->val = 3;
//    E->left = NULL;
//    E->right = NULL;
//
//    TNode* F = (TNode*)malloc(sizeof(TNode));
//    F->val = 4;
//    F->left = NULL;
//    F->right = NULL;
//
//    TNode* G = (TNode*)malloc(sizeof(TNode));
//    G->val = 4;
//    G->left = NULL;
//    G->right = NULL;
//
//    A->left = B;
//    A->right = C;
//    B->left = D;
//    D->left = F;
//    C->right = E;
//    E->right = G;
//
//   printf("%d", isBalanced(A));
//
//
//    return 0;
//}