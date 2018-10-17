class Solution {
	    public ListNode middleNode(ListNode head) {
	        int n = 0;
	        for(ListNode x = head;x != null; x = x.next, n++);

	        int m = n/2;
	        ListNode y = head;
	        for(int i = 0;i < m;i++, y = y.next);
	        return y;
	    }
	}

/*#include <cstdio>
#include <cstdlib>
#include <cstring>
#define rom (Link*)malloc(sizeof(Link))

char a[105];

typedef struct LINK
{
    int num;
    struct LINK *next;
}Link;


int main()
{
    scanf("%s",a);

    Link *head = rom;
    Link *tmp = head;
    int len = 0;

    for(int i = 0;i<strlen(a);i++)
    {
        Link *now = rom;
        now->num = a[i] - '0';
        now->next = NULL;
        tmp->next = now;
        tmp = tmp->next;
        ++len;
    }

    for(int i = 0;i<len/2;i++)
    {
        head = head->next;
    }

    head = head->next;
    while(head != NULL)
    {
        printf("%d ",head->num);
        head = head->next;
    }
    return 0;
}*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <cstdio>
#include <cstdlib>
#define rom (Link*)malloc(sizeof(Link))
 typedef struct ListNode {
      int val;
     struct ListNode *next;
  }Link;

struct ListNode* oddEvenList(struct ListNode* head) {
    int cnt = 0;
    struct ListNode *tmp = head;
    tmp = tmp->next;
    while(tmp)
    {
        ++cnt;
        tmp = tmp->next;
    }
    if(cnt == 1 || cnt == 2)
    {
        return head;
    }
    tmp = head;
    tmp = tmp->next;
    struct ListNode *pre = head->next->next,*last,*tmp1 = head->next;
    for(int i = 1;i<=cnt;i++)
    {
        if(tmp1->next)
        {
            tmp1 = tmp1->next;
        }
        if(i == cnt-1)
        {
            if(i % 2 == 0)
            {
                last = tmp->next;
                tmp->next = NULL;
            }
            if(i % 2 != 0)
            {
                last = tmp->next;
                tmp->next = pre;
            }
        }
        if(i == cnt)
        {
            if(i % 2 == 0)
            {
                last->next = NULL;
            }
            if(i % 2 != 0)
            {
                last->next = pre;

            }
        }
        if(i != cnt-1 && i != cnt)
        {
            tmp->next = tmp->next->next;
        }
        tmp = tmp1;
    }

return head;
}

int main()
{
    Link *head = rom;
    Link *tmp = head;
    for(int i = 1;i<6;i++)
    {
        Link *now = rom;
        now->val = i;
        now->next = NULL;
        tmp->next = now;
        tmp = tmp->next;
    }

    Link *p = oddEvenList(head);
    p = p->next;
    while(p)
    {
        printf("%d\n",p->val);
        p = p->next;
    }
}
