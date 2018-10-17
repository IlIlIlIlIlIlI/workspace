#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(m > n)
    {
        m %= n;
    }

    int a[n][n];
    for(int i = 0;i<n;i++)
    {
        a[0][i] = i+1;
        scanf("%d",&a[1][i]);
    }

    int j = 0;
    for(;j<n;j++)
    {

        if((j+m) == n)
        {
            break;
        }
    }

    for(int i = 0;i<n-j;i++)
    {
        a[0][j+i] = i;
    }

    for(int i = 0;i<j;i++)
    {
        a[0][i] = n-j+i;
    }

    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            if(a[0][i] == k)
            {
                printf("%d",a[1][i]);
                if(k != (n-1))
                {
                    printf(" ");
                }
                break;
            }
        }
    }
}
