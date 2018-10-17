#include<stdio.h>
void fun(int *a,int *b)
{
    int *c;
    c=a;
    a=b;
    b=c;
}
int main()
{
    int x=2,y=100;
    fun(&x,&y);
    printf("%d %d\n",x,y);
    return 0;
}
