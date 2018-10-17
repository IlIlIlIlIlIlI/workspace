#include<stdio.h>

#define maxn 1024
#define maxm 1024

char field[maxn][maxm];
int n,m;

void dfs(int x,int y)
{
    //先将当前位置替换为点'.'
    field[x][y] = '.';

    //循环遍历移动的方向
    for(int dx = -1;dx <= 1;dx++)
    {
        for(int dy = -1;dy <= 1;dy++)
        {
                int nx = x + dx;
                int ny = y + dy;

                //不能越界，且判断是否移动到的点为'w'
                if(nx >= 0 && ny >= 0 && nx <= n && ny <= m && field[nx][ny] == 'w')
                    dfs(nx,ny);
        }
    }

    //如果退出两重for循环即退出dfs函数，也即进行了一次dfs搜索，又即找到了一个水塘
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
