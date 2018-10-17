#include<stdio.h>
int ack(int m,int n)
{
    int ans;
    if(!m)
    {
        ans = n+1;
    }
    if(!n)
    {
        ans = ack(m-1,1);
    }
    if(m && n)
    {
        ans = ack(ack(m-1,n),n-1);
    }
    return ans;
}

int main()
{
    int ans = ack(2,2);
    printf("%d\n",ans);
}

/**
A(1,0)=2; (1)
A(0,m)=1 m>=0 (2)
A(n,0)=n+2, n>=2 (3)
A(n,m)=A(A(n-1,m),m-1) n,m>=1 (4)
*/
