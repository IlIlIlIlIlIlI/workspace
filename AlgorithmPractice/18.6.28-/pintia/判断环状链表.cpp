/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
        {
            return false;
        }
        ListNode *p1 = head, *p2 = head;
        int f = 0;
        while(1)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if(p2->next && p2->next == p1)
            {
                f = 1;
                break;
            }
        }
        if(p1 == p2 || f == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};