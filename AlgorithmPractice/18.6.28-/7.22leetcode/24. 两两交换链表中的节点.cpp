/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head || !head->next)
    {
        return head;
    }
    struct ListNode *tmp = head;
    struct ListNode *tmp1 = head;
    int f = 1;
    while(tmp)
    {
        if(tmp1->next && tmp1->next->next)
        {
            tmp1 = tmp1->next->next;
        }


    else
{
tmp1 = NULL;
}
        if(tmp->next)
        {
            struct ListNode *a = tmp->next;
            a->next = tmp;
            if(f)
            {
                head = a;
                f = 0;
            }
            if(tmp1)
            {
                if(tmp1->next != NULL)
                {
                    tmp->next = tmp1->next;
                }
                else
                {
                    tmp->next = tmp1;
                }
            }
            else
            {
                tmp->next = NULL;
            }
        }
        tmp = tmp1;
    }
    return head;
}
