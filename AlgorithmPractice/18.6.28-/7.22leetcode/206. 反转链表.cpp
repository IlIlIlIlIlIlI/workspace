/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //´íÎó´¦Àí
    if( head == NULL || head->next == NULL )
        return head;
    struct ListNode* temp = reverseList(head->next);
    head -> next -> next = head;
    head -> next =  NULL;
    return temp;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *tmp = head;
    struct ListNode *a = NULL;
    while(tmp)
    {
        struct ListNode *now = tmp;
        tmp = now->next;
        now->next = a;
        a = now;
    }
    return a;
}
