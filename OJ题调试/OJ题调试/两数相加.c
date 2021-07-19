//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
// 
//struct ListNode* reverse(struct ListNode* head)
//{
//    struct ListNode* newhead = NULL;
//    while (head)
//    {
//        struct ListNode* next = head->next;
//        head->next = newhead;
//        newhead = head;
//        head = next;
//    }
//    return newhead;
//}
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct LisAtNode* l2)
//{
//    struct ListNode* head1 = l1;
//    struct ListNode* head2 = l2;
//    int carry = 0;
//    while (head1);
//    {
//        head1->val += head2->val + carry;
//        carry = head1->val / 10;
//        head1->val %= 10;
//        head1 = head1->next;
//        head2 = head2->next;
//    }
//
//    l1 = reverse(l1); 
//    return l1;
//}
//
//int main()
//{
//    struct ListNode* A = (struct ListNode*)malloc(sizeof(struct ListNode));
//    A->val = 2;
//    A->next = NULL;
//
//    struct ListNode* B = (struct ListNode*)malloc(sizeof(struct ListNode));
//    B->val = 4;
//    B->next = NULL;
//
//    struct ListNode* C = (struct ListNode*)malloc(sizeof(struct ListNode));
//    C->val = 3;
//    C->next = NULL;
//
//    A->next = B;
//    B->next = C;
//
//
//    struct ListNode* D = (struct ListNode*)malloc(sizeof(struct ListNode));
//    D->val = 5;
//    D->next = NULL;
//
//    struct ListNode* E = (struct ListNode*)malloc(sizeof(struct ListNode));
//    E->val = 6;
//    E->next = NULL;
//
//    struct ListNode* F = (struct ListNode*)malloc(sizeof(struct ListNode));
//    F->val = 4;
//    F->next = NULL;
//
//    D->next = E;
//    E->next = F;
//
//    addTwoNumbers(A, D);
//}