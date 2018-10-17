#include<stdio.h>
#include<stdlib.h>
#define rom (Link*)malloc(sizeof(Link))

typedef struct LINK
{
    int coef;
    int expon;
    struct LINK *next;
}Link;

/*void newNode(int coef,int expon,Link *temp)
{
    Link *new = rom;
    new->coef = coef;
    new->expon = expon;
    new->next = NULL;
    temp->next = new;
    temp = temp->next;
}*/

Link* add(Link *a,Link *b)
{
    int sum;
    Link *ans = rom;
    Link *temp,*del;
    temp = ans;
    while(a && b)
    {
        if(a->expon < b->expon)
        {
            newNode(a->coef,a->expon,temp);
            a = a->next;
        }
        if(a->expon == b->expon)
        {
            sum = a->coef + b->coef;
            if(sum)
            {
                Link *new = rom;
    new->coef = sum;
    new->expon = a->expon;
    new->next = NULL;
    temp->next = new;
    temp = temp->next;
                //newNode(sum,a->expon,temp);
            }
            printf("%d\n",temp->coef); //!****!
            a = a->next;
            b = b->next;
        }
        if(b->expon < a->expon)
        {
            newNode(b->coef,b->expon,temp);
            b = b->next;
        }
    }
    for(;a;a = a->next)
    {
        newNode(a->coef,a->expon,temp);
    }
    for(;b;b = b->next)
    {
        newNode(b->coef,b->expon,temp);
    }
    del = temp;
    ans = ans->next;
    free(del);
    return ans;
}

void show(Link *ans)
{
    Link *last;
    while(ans->next)
    {
        last = ans;
        ans = ans->next;
    }

    while(ans)
    {
        if(ans == last)
        {
            printf("%dx^%d",last->coef,last->expon);
        }
        else
        {
            printf("%dx^%d+",ans->coef,ans->expon);
        }
    }
}

int main()
{
    Link *a = rom;
    Link *aTemp = a;
    Link *b = rom;
    Link *bTemp = b;

    for(int i = 0;i<7;i++)
    {
        Link *aNew = rom;
        aNew->coef = i;
        aNew->expon = i;
        aNew->next = NULL;
        aTemp->next = aNew;
        aTemp = aTemp->next;

        Link *bNew = rom;
        bNew->coef = i;
        bNew->expon = i;
        bNew->next = NULL;
        bTemp->next = bNew;
        bTemp = bTemp->next;
    }
    a = a->next;
    b = b->next;

    //printf("%d\n",a->coef); //!****!

    Link *ans = add(a,b);

    show(ans);
}

