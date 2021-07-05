/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    if (!head)
        return NULL;

    //创建复制节点 于 每个原始结点后边
    //0 2 4 6...2n 的位置为原链表的结点    
    //1 3 5 7...2n-1 的位置为复制链表的结点
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->next = NULL;
        copy->random = NULL;
        copy->val = cur->val;

        struct Node* next = cur->next;
        cur->next = copy;
        copy->next = next;

        cur = next;
    }
    //连接复制节点的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random)
        {
            copy->random = cur->random->next;
        }
        else
        {
            copy->random = NULL;
        }
        cur = cur->next->next;
    }

    //拆分出链表中复制的部分
    struct Node* copyHead = head->next;//保存复制链表的头
    struct Node* next = NULL;//原链表的下一个位置
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;//确定复制链表的地址
        next = copy->next;//保留第三个位置的地址

        cur->next = next;//先让原链表指向原链表的下一个位置
        if (next != NULL)//当next == NULL的时候，next->next是不存造的，所以在这判断一下
            copy->next = next->next;
        else
            copy->next = NULL;

        cur = cur->next;
    }
    return copyHead;

}