#include<stdio.h>
#include<string.h>
int a[101],n;
void qs(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp && i<j)  j--;
        while(a[i]<=temp && i<j)  i++;
            if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[j];
    a[j]=temp;
    qs(left,j-1);
    qs(j+1,right);
    return;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qs(0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n) printf(" ");
    }
    return 0;
}
