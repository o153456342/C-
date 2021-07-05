/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 //遍历一遍
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

//遍历两遍
// struct ListNode* middleNode(struct ListNode* head)
// {
//     int count = 0;
//     struct ListNode* cur =head;
//     while(cur)
//     {
//         cur = cur->next;
//         count++;
//     }
//     cur = head;
//     count /= 2;
//     while(count--)
//     {
//            cur = cur->next;
//     }
//     return cur;
// }