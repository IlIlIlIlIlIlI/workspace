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
        //如果当前节点小于头节点，则直接为新头
        if(pcur->val < head->val)
        {
            prev->next = pcur->next;

            pcur->next = head;
            head = pcur;

            pcur = prev->next;

            continue;
        }

        //如果当前节点小于前面节点,则需要插入到前面的链表中
        if(pcur->val < prev->val)
        {
            prev->next = pcur->next;

            //找到第一个大于该节点的前一个节点
            p = head;
            while(p->next->val < pcur->val)
            {
                p=p->next;
            }

            //找到后，把当前节点插入进去
            pcur->next = p->next;
            p->next = pcur;

            //恢复当前节点，继续前进
            pcur=prev->next;
        }
        //如果当前节点大于等于前面节点，则继续前进
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
