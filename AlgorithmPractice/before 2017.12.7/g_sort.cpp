#include<stdio.h>//归并排序
#include<algorithm>
using namespace std;
int n,a[10000],b[10000]={0};
void paixu(int l,int r)//把a数组的区间[l,r)排序
{
    int m=r-l;
    if(m<=1)return;
    int mid=(l+r)/2;
    paixu(l,mid);
    paixu(mid,r);
    int cnt=0,i=l,j=mid;
    while(i<mid&&j<r)
    {
        if(a[i]>a[j])b[cnt++]=a[j++];
        else b[cnt++]=a[i++];
    }
    while(i<mid)b[cnt++]=a[i++];
    while(j<r)b[cnt++]=a[j++];
    for(int i=0;i<cnt;i++)a[l+i]=b[i];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    /*******************************/
    //paixu(0,n);
    sort(a,a+n);
    /*******************************/
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}
/*
14
4 5 2 2 1 -3 -8 9 9 9 9 -8 -3 10
*/

