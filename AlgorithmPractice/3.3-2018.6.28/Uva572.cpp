#include<stdio.h>
#define maxn 1024
char field[maxn][maxn];
//bool book[maxn[maxn];
int n,m;

void dfs(int x,int y)
{
    field[x][y] = '*';

    //ѭ�������ƶ��ķ���
    for(int dx = -1;dx <= 1;dx++)
    {
        for(int dy = -1;dy <= 1;dy++)
        {
                int nx = x + dx;
                int ny = y + dy;

                //����Խ�磬���ж��Ƿ��ƶ����ĵ�Ϊ'w'
                if(nx >= 0 && ny >= 0 && nx <= n && ny <= m && field[nx][ny] == '@')
                    dfs(nx,ny);
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2 && n &&m)
    {
        for(int i = 0;i<n;i++)
        {
            scanf("%s",&field[i]);
        }

        //memset(book,false,sizeof(book));
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(field[i][j] == '@')
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
