#include<stdio.h>

#define maxn 1024
#define maxm 1024

char field[maxn][maxm];
int n,m;

void dfs(int x,int y)
{
    //�Ƚ���ǰλ���滻Ϊ��'.'
    field[x][y] = '.';

    //ѭ�������ƶ��ķ���
    for(int dx = -1;dx <= 1;dx++)
    {
        for(int dy = -1;dy <= 1;dy++)
        {
                int nx = x + dx;
                int ny = y + dy;

                //����Խ�磬���ж��Ƿ��ƶ����ĵ�Ϊ'w'
                if(nx >= 0 && ny >= 0 && nx <= n && ny <= m && field[nx][ny] == 'w')
                    dfs(nx,ny);
        }
    }

    //����˳�����forѭ�����˳�dfs������Ҳ��������һ��dfs�������ּ��ҵ���һ��ˮ��
    //return;
}

//

int main()
{

    scanf("%d%d",&n,&m);
    if(n >= 1 && n <= 100 && m >= 1 && m <= 100)
    {
            for(int i = 0;i<n;i++)
        {
            scanf("%s",&field[i]);
        }

        int res = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(field[i][j] == 'w')
                {
                    dfs(i,j);
                    res++;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
