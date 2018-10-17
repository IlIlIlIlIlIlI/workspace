#include<stdio.h>
#include<math.h>
int check(int n)
{
    if(n<2)
    {
        return 0;
    }
    int sqrtN = (int)sqrt(n);
    for(int i = 2;i<=sqrtN;i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y) == 2)
    {
        if(x == 0 && y == 0)
        {
            return 0;
        }
        int f = 1;
        for(int i = x;i<=y;i++)
        {
            int tmp = (i*i+i+41);
            if(check(tmp) == 0)
            {
                f = 0;
            }
        }
        if(f == 0)
        {
            printf("Sorry\n");
        }
        else
        {
            printf("OK\n");
        }
    }
    return 0;
}
