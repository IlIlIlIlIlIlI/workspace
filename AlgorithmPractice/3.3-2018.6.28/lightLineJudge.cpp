#include<stdio.h>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 505
using namespace std;

int gcd(int a,int b)
{
   if(a<b) swap(a,b);
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a % b);
    }
}

int main()
{
    int n,ans = 0;
    int x,y;
    int init[maxn];
    int dis[maxn][maxn];

    scanf("%d",&n);

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&init[i]);
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(i == j)
            {
                dis[i][j] = 0;
            }
            else
            {
                dis[i][j] = INF;
            }
        }
    }

    for(int i = 1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        dis[x][y] = dis[y][x] = 1;
    }

    /***********Floyd*********/
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    //每次更新dis[i][j]使其达到最小值
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    /***********Floyd*********/

    for(int i = 1;i<=n;i++)
    {
        for(int j = i + 1;j<=n;j++)
        {
            if(gcd(init[i],init[j]) == 1)
            {
                ans += dis[i][j];
            }
        }
    }
    printf("%d\n",ans);
}
