/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = cur->next;

    while (next)
    {

        if (cur->val != next->val)
        {
            prev = cur;
            cur = next;
        }
        else
        {
            while (next && cur->val == next->val)
            {
                cur->next = next->next;
                free(next);
                next = cur->next;
            }

            if (prev)
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }

            free(cur);
            cur = next;
        }
        if (next)
            next = cur->next;
    }
    return head;
}

// struct ListNode* deleteDuplicates(struct ListNode* head)
// {
//     if(head==NULL || head->next==NULL)
//     return head;

//     struct ListNode* cur = head;
//     struct ListNode* prev = NULL;
//     struct ListNode* next = cur->next;

//     while(next)
//     {
//         if(cur->val != next->val)
//         {
//             prev = cur;
//             cur = next;
//             next = cur->next;
//         }
//         else
//         {
//             while(cur->val == next->val)
//             {
//                 next = next->next;
//             } 

//             if(prev)
//             {
//                 prev->next = next;
//             }
//             else
//             {
//                 head = next;
//             }

//             while(cur != next)
//             {
//                 struct ListNode* del =cur;
//                 cur = cur->next;
//                 free(del);
//             }
//         }  
//     }
//     return head;
// }