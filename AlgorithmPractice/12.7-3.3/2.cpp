#include<stdio.h>
#include<math.h>
int main()
{
    int i,su=0,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        su+=i;
    printf("%d",su);
    return 0;
}
