#include<stdio.h>
int main()
{
    int a[4][5],b[20];
    for(int i=1;i<=20;i++)
        *(*a+i)=i;
        for(int i=1;i<=20;i++)
            printf("%d ",*(*a+i));
            printf("%d",*a);
    return 0;
}
