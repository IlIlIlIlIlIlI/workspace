#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000000];
int n,m,i;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
		sort(a,a+i);
    for(i=n-1;i>=n-m;i--)
        printf("%d ",a[i]);
return 0;
}
