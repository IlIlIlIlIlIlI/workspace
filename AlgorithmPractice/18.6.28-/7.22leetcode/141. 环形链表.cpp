/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *tmp = head;
    if(tmp && tmp->next == head)
    {
        return true;
    }
    while(tmp)
    {
        if(tmp->next  == head)
        {
            break;
        }
        tmp = tmp->next;
    }
    if(tmp)
    {
        return true;
    }
    else
    {
        return false;
    }
}
