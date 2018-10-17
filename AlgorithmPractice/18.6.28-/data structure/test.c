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
    Link *L = rom;
    Link *tem = L;
    for(int i = 1;i<=n;i++)
    {
        Link *new = rom;
        new->id = i;
        tem->next = new;
        tem = tem->next;
    }
    L = L->next;
    tem->next = L;
    return L;
}

void findAndKillK(Link *p,int k,int m)
{
    Link *tem = p;
    while(tem->id != k)
    {
        tem = tem->next;
    }
    Link *del;
    /*
    *很重要！的思路
    */
    while(tem->next != tem)
    {
        for(int i = 1;i<m;i--)
        {
            del = tem;  //!将目标的上一个节点保存
            tem = tem->next;
        }
        del->next = tem->next;
    }
    printf("%d\n",tem->id);
}

int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    Link *node = initLink(n);
    findAndKillK(node,k,m);
}
