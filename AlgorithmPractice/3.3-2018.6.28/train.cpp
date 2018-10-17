#include<stdio.h>
#define maxn 1010
#define INF 0x3f3f3f3f
int n,m;
int min = INF;
int book[maxn];
int dis[maxn];
int next[maxn][maxn];

void init()
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(i == j)
            {
                next[i][j] = 0;
            }
            else
            {
                next[i][j] = INF;
            }
        }
    }

    for(int i = 1;i<=n;i++)
    {
        dis[i] = next[1][i];
    }

    for(int i = 1;i<=n;i++)
    {
        book[1] = 1;
        book[i] = 0;
    }
}

void Dijkstra()
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(min > dis[j] && book[j] == 0)
            {
                min = dis[j];
                int nowNode = j;
            }
        }
        book[nowNode] = 1;
        for(int k = 1;k<=n;k++)
        {
            if(next[nowNode][k] < INF)
            {
                if(dis[k] > dis[nowNode] + next[nowNode][k])
                {
                    dis[k] = dis[nowNode] + next[nowNode][k];
                }
            }
        }
    }
}

void check(int a,int b)
{
    if()
}

int main()
{
    while(scanf("%d%d",&n,&m) && n && m)
    {
        for(int i = 1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
        }

        int start,end;
        scanf("%d%d",&start,&end);

        init();
        Dijkstra();

    }
}
