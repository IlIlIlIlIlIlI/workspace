#include<stdio.h>
#include<string.h>
#define maxn 1024
#define INF 0x3f3f3f3f

int n,m;//��ͱ�
int book[maxn];
int next[maxn][maxn];
int dis[maxn];

void init()
{
    //��ʼ��next����
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

    //��ʼ��dis����
    for(int i = 1;i<=n;i++)
    {
        dis[i] = next[1][i];
    }

    //��ʼ��book����
    memset(book,0,sizeof(book));

    //Ĭ��ѡ���׽��
    book[1] = 1;

    /***********Dijsktra******************/
    for(int i = 1;i<=n-1;i++)
    {
        int minm = INF;

        //�ҵ�����Դ������ĵ�
        int nowNode;
        for(int j = 1;j<=n;j++)
        {
            if(book[j] == 0 && dis[j] < minm)
            {
                minm = dis[j];

                //��������
                nowNode = j;
            }
        }
        book[nowNode] = 1;//���
        for(int k = 1;k<=n;k++)
        {

            //�ж���·����
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
