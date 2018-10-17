class Solution {
public:
    
    // 先计算得长度，找到中点，然后将前一半的链表翻转，然后比较即可
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head -> next) return true;
        int len = 0;
        ListNode* p = head;
        while (p) len++, p = p -> next; //!从本质上讲，逗号的作用是导致一系列运算被顺序执行。
        ListNode* tail = NULL;
        ListNode* M = head;
        p = head;
        int mid;
        ListNode* nex = head;
        if (len & 1) {
            int mid = len / 2 + 2;
            int cnt = 0;
            while (cnt++ < (mid - 1)) {
                M = M -> next;
            }
            mid -= 2;
            while (mid--) {
                nex = p -> next;
                p -> next = tail;
                tail = p;
                p = nex;
            }            
        }
        else {
            int mid = len / 2 + 1;
            int cnt = 0;
            while (cnt++ < (mid - 1)) M = M -> next;
            mid--;
            cout << mid << endl;
            while (mid--) {
                nex = p -> next;
                p -> next = tail;
                tail = p;
                p = nex;
            }   
            
        } 
        while (tail) {
            if (tail -> val != M -> val) return false;
            tail = tail -> next; M = M -> next;
        }
        return true;      
        
    }
};




static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *tmp = head;
        while(tmp)
        {
            s.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp)
        {
            if(s.top() == tmp->val)
            {
                s.pop();
            }
            tmp = tmp->next;
        }
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};