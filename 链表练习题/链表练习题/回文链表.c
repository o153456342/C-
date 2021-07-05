/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head)
{
    if (!head || !head->next)
        return true;
    //找中间结点
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    //逆置后半部分链表
    struct ListNode* newHead = NULL;
    struct ListNode* next = NULL;
    while (slow)
    {
        next = slow->next;
        slow->next = newHead;
        newHead = slow;
        slow = next;
    }

    while (head)
    {
        if (head->val != newHead->val)
        {
            return false;
        }
        head = head->next;
        newHead = newHead->next;
    }
    return true;
}