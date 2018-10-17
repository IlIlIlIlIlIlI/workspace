#include<stdio.h>
#include<string.h>
typedef struct LINK
{
    int val;
    struct LINK *next;
}List;

int main()
{
List *head = (List*)malloc(sizeof(List));
List *tmp = head;
    for(int i = 0; i < 10; i++)
{
    List *now = (List*)malloc(sizeof(List));
    now->val = i;
now->next = NULL;
    tmp->next = now;
    tmp = tmp->next;
}

    List *pa = head->next->next;
    while(pa && pa->next)
{
    List *tmp = pa->next;
    pa->next = head->next;
    head->next = pa;
    pa = tmp;
}
    tmp = head->next;
while(tmp)
{
    printf("%d\n", tmp->val);
tmp = tmp->next;
}
return 0;
}
