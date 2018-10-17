/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *prev=head,  *pcur=head->next, *p=NULL;

    while(pcur)
    {
        //�����ǰ�ڵ�С��ͷ�ڵ㣬��ֱ��Ϊ��ͷ
        if(pcur->val < head->val)
        {
            prev->next = pcur->next;

            pcur->next = head;
            head = pcur;

            pcur = prev->next;

            continue;
        }

        //�����ǰ�ڵ�С��ǰ��ڵ�,����Ҫ���뵽ǰ���������
        if(pcur->val < prev->val)
        {
            prev->next = pcur->next;

            //�ҵ���һ�����ڸýڵ��ǰһ���ڵ�
            p = head;
            while(p->next->val < pcur->val)
            {
                p=p->next;
            }

            //�ҵ��󣬰ѵ�ǰ�ڵ�����ȥ
            pcur->next = p->next;
            p->next = pcur;

            //�ָ���ǰ�ڵ㣬����ǰ��
            pcur=prev->next;
        }
        //�����ǰ�ڵ���ڵ���ǰ��ڵ㣬�����ǰ��
        else
        {
            prev=pcur;
            pcur=pcur->next;
        }
    }

    return head;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *preHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    preHead->next = head;
    if(!head)
    {
        return head;
    }
    struct ListNode *curr = head->next;
    struct ListNode *pre = head;
    while(curr)
    {
        if(curr->val < pre->val)
        {
            struct ListNode *nextNode = curr->next;

            struct ListNode *tmp = preHead;
            struct ListNode *curr2 = preHead->next;
            while(curr->val > curr2->val && curr2 != pre)
            {
                tmp = curr2;
                curr2 = curr2->next;
            }
            tmp->next = curr;
            curr->next = curr2;
            pre->next = nextNode;

            curr = nextNode;
        }
        else
        {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}
