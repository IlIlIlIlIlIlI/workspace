/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *tmp = node;

struct ListNode *last;
    while(tmp->next != NULL)
    {

    if(tmp->next->next == NULL)
    {
        last = tmp;
    }
        tmp->val = tmp->next->val;
        tmp = tmp->next;
    }
    last->next = NULL;
}
