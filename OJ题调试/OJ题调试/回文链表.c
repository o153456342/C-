//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
// struct ListNode {
//    int val;
//     struct ListNode *next;
// };
// 
//
//struct ListNode* ReverseList(struct ListNode* plist)
//{
//    struct ListNode* newnode = NULL;
//    struct ListNode* cur = plist;
//    struct ListNode* next = plist->next;
//    while (cur)
//    {
//        cur->next = newnode;
//        newnode = cur;
//        cur = next;
//        if (next)
//            next = cur->next;
//    }
//    return newnode;
//}
//
//bool isPalindrome(struct ListNode* head)
//{
//    if (head->next || head)
//        return true;
//
//    struct ListNode* prev = NULL;
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        prev = slow;
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    prev->next = NULL;
//    struct ListNode* newlist = ReverseList(slow);
//    while (head)
//    {
//        if (head->val != newlist->val)
//            return false;
//        else
//        {
//            head = head->next;
//            newlist = newlist->next;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    struct ListNode* A = (struct ListNode*)malloc(sizeof(struct ListNode));
//    A->val = 1;
//    A->next = NULL;
//
//    struct ListNode* B = (struct ListNode*)malloc(sizeof(struct ListNode));;
//    B->val = 2;
//    B->next = NULL;
//
//    A->next = B;
//    
//    int ret = isPalindrome(A);
//    printf("%d", ret);
//    return 0;
//
//}