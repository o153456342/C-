/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
 //     if (headA == NULL || headB == NULL) {
 //         return NULL;
 //     }
 //     struct ListNode *pA = headA, *pB = headB;
 //     while (pA != pB) {
 //         pA = pA == NULL ? headB : pA->next;
 //         pB = pB == NULL ? headA : pB->next;
 //     }
 //     return pA;
 // }


struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while (curA != curB)
    {
        if (curA == NULL)
        {
            curA = headB;
        }
        else
        {
            curA = curA->next;
        }
        if (curB == NULL)
        {
            curB = headA;
        }
        else
        {
            curB = curB->next;
        }
    }
    return curA;
}


// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
// {
//     //������������
//     struct ListNode* cur = headA;
//     int La=0;
//     while(cur)
//     {
//         cur = cur->next;
//         La++;
//     }    
//     int Lb=0;
//     cur = headB;
//     while(cur)
//     {
//         cur = cur->next;
//         Lb++;
//     }
//     //�жϳ���
//     struct ListNode* longList = headA;
//     struct ListNode* shortList = headB;
//     if(Lb>La)
//     {
//         longList = headB;
//         shortList = headA;
//     }
//     int gap = abs(Lb-La);
//     //�ó������ƶ�һ���֣�ֱ��ʣ�µĽ��������̵���ͬ
//     while(gap--)
//     {
//         longList = longList->next;
//     }
//     //ͬʱ��ʼ���������ȶԵ�ַ
//     while(longList)
//     {
//         if(longList == shortList)
//         return longList;

//         longList = longList->next;
//         shortList = shortList->next;
//     }
//     return NULL;
// }