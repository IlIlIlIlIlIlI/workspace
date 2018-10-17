#include<stdio.h>
#include<math.h>
int main()
{
int n=0,m,i,k;
 for(m=2;m<=1000;m++)
 {
    k=sqrt(m);
    for(i=2;i<=k;i++)
        if(m%i==0)
            break;

    if(i>k)
    {
        printf("%d\t",m);
        n=n+1;
        if(n%10==0)
        printf("\n");
    }



 }
    return 0;
}
