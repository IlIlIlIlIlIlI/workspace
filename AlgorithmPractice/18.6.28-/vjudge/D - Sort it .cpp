#include <cstdio>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int dp[1003];
        for(int i=0;i<n;i++)
        scanf("%d",&dp[i]);

        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dp[i]>dp[j])
                {
                    int temp=dp[i];
                    dp[i]=dp[j];
                    dp[j]=temp;
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
