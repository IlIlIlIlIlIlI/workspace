#include<stdio.h>
#define AA 100
int main()
{
    int i,b,k=0;
    for(i=1;i<=5;i++)
    {
        b=i%2;
        while(b-->=0) k++;
    }
    printf("%d %d ",k,b);
return 0;
}



