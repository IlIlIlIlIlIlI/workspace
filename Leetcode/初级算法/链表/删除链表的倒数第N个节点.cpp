class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       return remove(head,&n,NULL);
    }
    
    ListNode* remove(ListNode* head,int *n,ListNode* pre){
        if(head == NULL)return NULL;
         remove(head->next,n,head);
         if(*n==0)return head;
        (*n)--;
        if(*n==0){
            if(pre != NULL){
                
                pre->next = head->next;
                head= NULL;
            }else{
                return head->next;
            }
        }
        return pre;
    }
    
};




class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode * scan_ptr = head;
		for (int i = 0; i < n; i++) {
			scan_ptr = scan_ptr->next;
		}
		if (scan_ptr == NULL) {
			ListNode*temp = head;
			head = head->next;
			//delete temp;
		}
		else {
			ListNode * tail_ptr = head;
			while (scan_ptr->next != NULL) {
				scan_ptr = scan_ptr->next;
				tail_ptr = tail_ptr->next;
			}
			ListNode * temp = tail_ptr->next;
			tail_ptr->next = tail_ptr->next->next;
			//delete temp;
		}
        return head;
	}
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        int cnt = 0;
        while(tmp)
        {
            cnt++;
            tmp = tmp->next;
        }
        int i = 0;
        ListNode *tmp1 = new ListNode(0);
        tmp1->next = head;
        tmp = tmp1;
        while(i++ < (cnt-n))
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return tmp1->next;
    }
};