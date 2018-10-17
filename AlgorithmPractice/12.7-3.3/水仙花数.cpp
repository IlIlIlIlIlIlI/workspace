#include<stdio.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n) == 2)
    {
        //if(100 <= m && n <= 999 && m < n)
        //{
            int f = 1;
            int cnt = 0;
            for(int i=m;i<=n;i++)
            {
                int a=i/100;
                int b=i/10%10;
                int c=i%10;
                if(i==a*a*a+b*b*b+c*c*c)
                {
                    if(f)
                    {
                        printf("%d",i);
                        f = 0;
                    }
                    else
                    {
                        printf(" %d",i);
                    }

                    cnt++;
                }
            }
            if(cnt == 0)
            {
                printf("no\n");
            }
            else
            {
                printf("\n");
            }
        //}
    }

    return 0;
}
