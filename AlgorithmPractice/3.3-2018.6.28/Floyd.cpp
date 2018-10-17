/**
�����ȿӵ㣺

1. ���漰����Ҫ������Խϴ������ռ�ʱ�����������鿪��main��������

2. �����˱�������ֵʱ��ȷ���ģ���ʱ��������������ѭ�����У�����ɳ������д���
*/
#include<stdio.h>
#define INF 999999
#define maxn 205
int dis[maxn][maxn];

int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m) !=EOF)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
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

        int x,y,z;
        for(int i = 0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(z < dis[x][y])
            {
                dis[x][y] = dis[y][x] = z;
            }
        }

        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        int begining,ending;
        scanf("%d%d",&begining,&ending);

        if(dis[begining][ending] == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",dis[begining][ending]);
        }
    }
}
