/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // struct ListNode* reverseList(struct ListNode* head)
 // {
 //     struct ListNode* newhead = NULL;
 //     struct ListNode* cur = head;
 //     while(cur)
 //     {
 //     struct ListNode* next = cur->next;
 //     cur->next = newhead;
 //     newhead = cur;
 //     cur = next;
 //     }
 //     return newhead;
 // }


struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}