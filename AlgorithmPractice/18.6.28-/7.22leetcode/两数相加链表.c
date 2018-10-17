#include<stdio.h>
#include<stdlib.h>
#define rom (Link*)malloc(sizeof(Link))
typedef struct LINK
{
    int num;
    struct LINK *next;
}Link;

Link* initLink()
{
    int x;
    scanf("%d",&x);
    Link *head = rom;
    Link *tmp = head;
    for(int i = 0;i<x;i++)
    {
        int y;
        scanf("%d",&y);
        Link *new = rom;
        new->num = y;
        new->next = NULL;
        tmp->next = new;
        tmp = tmp->next;
    }
    return head->next;
}

void add(Link *p,Link *q)
{
    Link *tmpP = p;
    Link *tmpQ = q;
    Link *curr = rom;
    Link *tmp = curr;
    int carry = 0;
    while(tmpP != NULL || tmpQ != NULL)
    {
        int x = (tmpP == NULL) ? 0 : tmpP->num;
        int y = (tmpQ == NULL) ? 0 : tmpQ->num;
        int sum = carry + x + y;
        carry = sum/10;

        Link *new = rom;
        new->num = sum%10;
        new->next = NULL;
        tmp->next = new;
        tmp = tmp->next;

        if(tmpP != NULL)
        {
            tmpP = tmpP->next;
        }
        if(tmpQ != NULL)
        {
            tmpQ = tmpQ->next;
        }
    }
    if(carry)
    {
        Link *new = rom;
        new->num = 1;
        new->next = NULL;
        tmp->next = new;
        tmp = tmp->next;
    }

    curr = curr->next;
    int check = 1;
    while(curr)
    {
        if(check)
        {
            printf("%d",curr->num);
            check = 0;
        }
        else
        {
            printf(" %d",curr->num);
        }
        curr = curr->next;
    }
}

int main()
{
    Link *p = initLink();
    Link *q = initLink();
    add(p,q);
}
