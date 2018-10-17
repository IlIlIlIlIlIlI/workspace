//!Õætm²Ë¼¦Ò»¸ö!
/*
#include<stdio.h>
#define maxn 30+5
char maze[maxn][maxn];
int L,R,C;
void dfs(int x,int y)
{
    int dxy[8][2] = {(0,-1),(1,-1),
                     (1,0),(1,1),
                     (0,1),(-1,1),
                     (-1,0),(-1,-1)};
     for(int dx = 0;dx<8;dy++)
     {
         for(int dy = 0;dy<2;dy++)
         {
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx <= R && ny >= 0 && ny <= C)
            {
                if(maze[nx][ny] == 'E')
                {
                    ans++;
                    return;
                }
                if(maze[nx][ny] == '.')
                {
                    ans++;
                    dfs(nx,ny);
                }
            }
         }
     }


}
int main()
{
    while(scanf("%d%d%d",&L,&R,&C) && L <= 30 && R <= 30 && C <=30)
    {
        while(L--)
        {
            for(int j = 0;j<R;j++)
            {
                scanf("%s",&maze[j]);
            }
            printf("\n");
        }

        int ans = 0;
        bool ok = false;
        for(int i = 0;i<R;i++)
        {
            for(int j = 0;j<C;j++)
            {
                if(maze[i][j] = 'S')
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        if(ok)
        {
            printf("Escaped in %d minute(s).\n",ans);
        }
        else
        {
            printf("Trapped!\n");
        }
    }
}
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct node
{
    int x,y,z,step;
};
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int n,m,r,sx,sy,sz,ex,ey,ez;
char a[35][35][35];
int book[35][35][35];
int bfs(int sx,int sy,int sz,int ex,int ey,int ez)
{
    queue<node>q;
    node fr,ne;
    fr.x=sx,fr.y=sy,fr.z=sz,fr.step=0;
    book[fr.x][fr.y][fr.z]=1;
    q.push(fr);
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        if(fr.x==ex&&fr.y==ey&&fr.z==ez)
        {
            return fr.step;
        }
        for(int i=0;i<6;i++)
        {
            ne.x=fr.x+dir[i][0];
            ne.y=fr.y+dir[i][1];
            ne.z=fr.z+dir[i][2];
            if(a[ne.x][ne.y][ne.z]!='#'&&ne.x>=0&&ne.x<n&&ne.y>=0&&ne.y<m&&ne.z>=0&&ne.z<r&&book[ne.x][ne.y][ne.z]==0)
            {
                book[ne.x][ne.y][ne.z]=1;
                ne.step=fr.step+1;
                q.push(ne);
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&r))
    {
        if(n==0&&m==0&&r==0)
        {
            break;
        }
        memset(a,'\0',sizeof(a));
        memset(book,0,sizeof(book));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%s",&a[i][j]);
                for(int k=0;k<r;k++)
                {
                    if(a[i][j][k]=='S')
                    {
                        sx=i;
                        sy=j;
                        sz=k;
                    }
                    if(a[i][j][k]=='E')
                    {
                        ex=i;
                        ey=j;
                        ez=k;
                    }
                }
            }
        }
        int re=bfs(sx,sy,sz,ex,ey,ez);
        if(re==-1)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",re);
        }
    }
    return 0;
}
