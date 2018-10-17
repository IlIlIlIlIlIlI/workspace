#include <cstdio>
#include <cmath>
#include <string.h>

const int maxn = 22;
int ok[maxn];
int prime[2*maxn];
int ans[maxn];
int n;

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

void show(int a[])
{
    int f = 1;
    for(int i = 1;i<=n;i++)
    {
        if(f)
        {
            printf("%d",a[i]);
            f = 0;
        }
        else
        {
            printf(" %d",a[i]);
        }
    }
    printf("\n");
}

void dfs(int start)
{
    if(start > n && prime[ans[1] + ans[n]] == 1)
    {
        show(ans);
    }
    for(int i = 2;i<=n;i++)
    {
        ans[start] = i;
        if(prime[ans[start]+ans[start-1]] == 1 && !ok[i])
        {
            ok[i] = 1;
            dfs(start+1);
            ok[i] = 0;//!*********
        }
    }
}

int main()
{
    memset(prime,0,sizeof(prime));
    for(int i = 1;i<=39;i++)
        {
            if(check(i))
            {
                prime[i] = 1;
            }
        }

    int k = 0;
    while(scanf("%d",&n) == 1)
    {
        printf("Case %d:\n",++k);
        memset(ok,0,sizeof(ok));
        ans[1] = 1;
        dfs(2);
        printf("\n");
    }
    return 0;
}
