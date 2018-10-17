/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node = NULL;
    struct ListNode **tmp = &node;
    struct ListNode *t1 = l1;
    struct ListNode *t2 = l2;
    while (t1 != NULL || t2 != NULL) {
        if (*tmp == NULL) {
            *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
            memset(*tmp, 0, sizeof(struct ListNode));
        }

        if (t2 == NULL || (t1 != NULL && t1->val < t2->val)) {
            (*tmp)->val = t1->val;
            t1 = t1->next;
            tmp = &(*tmp)->next;
        } else {
            (*tmp)->val = t2->val;
            t2 = t2->next;
            tmp = &(*tmp)->next;
        }
    }
    return node;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL){
        return l2;
    }

    if(l2==NULL){
        return l1;
    }

    struct ListNode head;
    head.next=NULL;

    struct ListNode* node=&head;

    while(l1!=NULL||l2!=NULL){
        if(l1!=NULL){
            if(l2!=NULL){
                if(l1->val>l2->val){
                    node->next=l2;
                    l2=l2->next;
                    node=node->next;
                    continue;
                }

                node->next=l1;
                l1=l1->next;
                node=node->next;
            }else{
                node->next=l1;
                break;
            }
        }else{
            node->next=l2;
            break;
        }
    }


    return head.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *tmp1 = l1;
    struct ListNode *tmp2 = l2;
    struct ListNode *l;
    if(l1->val > l2->val)
    {
        l = l1;
        l1 = l2;
        l2 = l;
    }
    if(l1->next == NULL)
    {
        l1->next = l2;
        return l1;
    }

    /*while(tmp2->next)
    {
        if(tmp2->val > tmp2->next->val)
            {
                int a = tmp2->val;
                tmp2->val = tmp2->next->val;
                tmp2->next->val = a;
            }
            tmp2 = tmp2->next;
    }*/
    while(tmp2)
    {
        if(!tmp1)
        {
            tmp1 = tmp2;
            return l1;
        }
        if(tmp1->val <= tmp2->val)
        {
            if(tmp1->next == NULL || tmp1->next->val >= tmp2->val)
            {
                l = tmp2;
                tmp2 = tmp2->next;
                l->next = tmp1->next;
                tmp1->next = l;
            }
            tmp1 = tmp1->next;
        }
        else
        {
            tmp2 = tmp2->next;
        }
    }
    return l1;
}
