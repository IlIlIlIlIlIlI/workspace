#include<stdio.h>
#include<string.h>
#define maxn 1024
#define INF 0x3f3f3f3f

int n,m;//点和边
int book[maxn];
int next[maxn][maxn];
int dis[maxn];

void init()
{
    //初始化next数组
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
}

int main()
{
    scanf("%d%d",&n,&m);

    int x,y,z;
    for(int i = 1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(next[x][y] < z)
        {
            next[x][y] = z;
        }
    }

    init();

    //初始化dis数组
    for(int i = 1;i<=n;i++)
    {
        dis[i] = next[1][i];
    }

    //初始化book数组
    memset(book,0,sizeof(book));

    //默认选中首结点
    book[1] = 1;

    /***********Dijsktra******************/
    for(int i = 1;i<=n-1;i++)
    {
        int minm = INF;

        //找到距离源点最近的点
        int nowNode;
        for(int j = 1;j<=n;j++)
        {
            if(book[j] == 0 && dis[j] < minm)
            {
                minm = dis[j];

                //坐标点更换
                nowNode = j;
            }
        }
        book[nowNode] = 1;//标记
        for(int k = 1;k<=n;k++)
        {

            //判断有路可走
            if(next[nowNode][k] < INF)
            {
                if(dis[k] > dis[nowNode] + next[nowNode][k])
                {
                    dis[k] = dis[nowNode] + next[nowNode][k];
                }
            }
        }
    }
    /***********Dijsktra******************/
    printf("%d\n",&dis[6]);
}
