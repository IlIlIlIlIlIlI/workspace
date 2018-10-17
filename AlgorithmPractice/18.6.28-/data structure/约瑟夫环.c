#include<stdio.h>
#include<stdlib.h>
#define rom (Link*)malloc(sizeof(Link))
typedef struct LINK
{
    int id;
    struct LINK *next;
}Link;

Link* initLink(int n)
{
    Link *head = rom;
    Link *tmp = head;
    for(int i = 0;i<n;i++)
    {
        Link *new = rom;
        new->id = i+1;
        new->next = NULL;
        tmp->next = new;
        tmp = tmp->next;
    }
    tmp->next = head->next;
    return head->next;
}

void findAndKillK(Link *p,int k,int n)
{
    Link *tmp = p;
    Link *pre = p;
    while(pre->next != p)
    {
        pre = pre->next;
    }
    while(tmp->id != k)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    while(tmp->next != tmp)
    {
      for(int i = 1;i<n;i++)
      {
          pre = tmp;
          tmp = tmp->next;
      }
      pre->next = tmp->next;
      free(tmp);
      tmp = pre->next;
    }
    printf("%d\n",tmp->id);
    free(tmp);
}

int main()
{
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m) == 3)
    {
        Link *link = initLink(n);
        findAndKillK(link,k,m);
    }
}
