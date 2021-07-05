/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* SortHead = head;
    struct ListNode* cur = head->next;
    SortHead->next = NULL;

    while (cur)
    {
        struct ListNode* next = cur->next;

        if (cur->val <= SortHead->val)
        {
            //头插
            cur->next = SortHead;
            SortHead = cur;
        }
        else
        {
            struct ListNode* Sortcur = SortHead->next;
            struct ListNode* Sortprev = SortHead;
            while (Sortcur)
            {
                if (cur->val <= Sortcur->val)
                {
                    //中间插入
                    Sortprev->next = cur;
                    cur->next = Sortcur;
                    break;
                }
                else
                {
                    Sortprev = Sortcur;
                    Sortcur = Sortcur->next;
                }
            }
            if (Sortcur == NULL)
            {
                //尾插
                Sortprev->next = cur;
                cur->next = NULL;
            }
        }


        cur = next;

    }
    return SortHead;
}