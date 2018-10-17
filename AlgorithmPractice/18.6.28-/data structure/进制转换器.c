#include<stdio.h>
#define maxn 1024

char data[maxn];
int top = -1;

void push(char ch)
{
    data[++top] = ch;
}

void pop()
{
    printf("%d",data[top]);
    top--;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    while(n != 0)
    {
        int tem = n%k;
        n /= k;
        push((char)tem);
    }
    while(top != -1)
    {
        pop();
    }
}
