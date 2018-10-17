#include<stdio.h>
#define maxn 100

int a[maxn];
int top = -1;

void push(int *a,int elem)
{
    if(++top <= maxn)
    {
        a[++top] = elem;
    }
    else
    {
        return;
    }
}

int pop(int *a)
{
    if(top != -1)
    {
        printf("%3d",a[top]);
        a[top] = 0;
        top--;
    }
    else
    {
        return;
    }
}

int main()
{
    for(int i = 0;i<99;i++)
    {
        push(a,i);
        pop(a);
        if(i % 5 == 0)
        {
            printf("\n");
        }
    }
}
