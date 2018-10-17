#include<stdio.h>
int n,a[10000],num[10000]={0};
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    for(int i=0;i<n;i++)
    {
        num[a[i]]++;
    }
    for(int i=0;i<10000;i++)
    {
        while(num[i]--)
        {
            printf("%d ",i);
        }
    }

}
/*
5
4 5 2 2 1
*/

