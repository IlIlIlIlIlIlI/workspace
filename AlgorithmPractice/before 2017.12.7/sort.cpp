#include<stdio.h>
int n,a[10000],b[10000];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
        for(int j=i;j>0;j--)
        {
            if(b[j-1]>b[j])
            {
                int t=b[j-1];b[j-1]=b[j];b[j]=t;
            }
            else break;
        }
    }
    for(int j=0;j<n;j++)
        printf("%d ",b[j]);
}
/*
5
4 5 2 2 1
*/
