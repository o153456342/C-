/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
**/


//递归
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
// {
//     if (!l1)
// 		return l2;
// 	if (!l2)
// 		return l1;
//     struct ListNode* head = NULL;
//     struct ListNode* tail = NULL;
//     带哨兵位的头结点，不储存有效数据，方便尾插
//     head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

//     // if(l1->val <= l2 ->val)
//     // {
//     //     head = l1;
//     //     tail = l1;
//     //     l1 = l1->next;
//     // }
//     // else
//     // {
//     //     head = l2;
//     //     tail = l2;
//     //     l2 = l2->next;
//     // }
//     while(l1 && l2)
//     {
//         if(l1->val <= l2->val)
//         {
//             tail->next = l1;
//             l1 = l1->next;
//         }
//         else
//         {
//             tail->next = l2;
//             l2 = l2->next;
//         }
//         tail = tail->next;
//     }
//     if(l1)
//     tail->next = l1;
//     else if(l2)
//     tail->next = l2;
//     // return head;
//     return head->next;
// }



// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
// {

//     if (!l1)
// 		return l2;
// 	if (!l2)
// 		return l1;
//     struct ListNode* newHead=NULL;
//     struct ListNode* cur1 = l1;
//     struct ListNode* cur2 = l2;
//     struct ListNode* next1 = NULL;
//     struct ListNode* next2 = NULL;
//     struct ListNode* ret =NULL;
//     while(cur1 || cur2)
//     {
//         if(cur1 == NULL)
//         {
//             next2 = cur2->next;
//             cur2->next = NULL;
//             newHead->next = cur2;
//             newHead = cur2;
//             cur2 = next2;
//         }
//         else if(cur2 == NULL)
//         {
//             next1 = cur1->next;
//             cur1->next = NULL;
//             newHead->next = cur1;
//             newHead = cur1;
//             cur1 = next1;            
//         }
//         else if(cur1->val <= cur2->val)
//         {
//             if(cur1 == l1 && cur2 == l2)
//             {
//                 newHead = cur1;
//                 ret = cur1;
//             }
//             next1 = cur1->next;
//             cur1->next = NULL;
//             newHead->next = cur1;
//             newHead = cur1;
//             cur1 = next1;
//         }
//         else
//         {
//             if(cur1 == l1 && cur2 == l2)
//             {
//                 newHead = cur2;
//                 ret = cur2;
//             }
//             next2 = cur2->next;
//             cur2->next = NULL;
//             newHead->next = cur2;
//             newHead = cur2;
//             cur2 = next2;
//         }
//     }
//     return ret;
// }