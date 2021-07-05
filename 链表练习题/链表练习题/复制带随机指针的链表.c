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

    //�������ƽڵ� �� ÿ��ԭʼ�����
    //0 2 4 6...2n ��λ��Ϊԭ����Ľ��    
    //1 3 5 7...2n-1 ��λ��Ϊ��������Ľ��
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
    //���Ӹ��ƽڵ��random
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

    //��ֳ������и��ƵĲ���
    struct Node* copyHead = head->next;//���渴�������ͷ
    struct Node* next = NULL;//ԭ�������һ��λ��
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;//ȷ����������ĵ�ַ
        next = copy->next;//����������λ�õĵ�ַ

        cur->next = next;//����ԭ����ָ��ԭ�������һ��λ��
        if (next != NULL)//��next == NULL��ʱ��next->next�ǲ�����ģ����������ж�һ��
            copy->next = next->next;
        else
            copy->next = NULL;

        cur = cur->next;
    }
    return copyHead;

}