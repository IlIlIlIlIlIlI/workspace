#include<stdio.h>
#include<string.h>
#include<queue>
#define maxn 50
using namespace std;

char maze[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int L,R,C;

struct node
{
    int x,y,z;
    int time;
}Begin,End;

queue<node> q;

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {1,-1,0,0,0,0};

int bfs()
{

    q.push(Begin);
    vis[Begin.x][Begin.y][Begin.z] = 1;
    while(!q.empty())
    {
        node front = q.front();
        q.pop();
        if(front.x == End.x && front.y == End.y && front.z == End.z)
            return front.time;
        for(int i = 0;i<6;i++)
        {
            node tmp;
            tmp.x = front.x + dx[i];
            tmp.y = front.y + dy[i];
            tmp.z = front.z + dz[i];
            if(tmp.x >= 0 && tmp.x < L &&
               tmp.y >= 0 && tmp.y < R &&
               tmp.z >= 0 && tmp.z < C &&
               !vis[tmp.x][tmp.y][tmp.z] &&
               maze[maxn][maxn][maxn] != '#'
               )
            {
                vis[tmp.x][tmp.y][tmp.z] = 1;
                tmp.time = front.time + 1;
                q.push(tmp);
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d%d",&L,&R,&C))
    {
        if(L == 0 && R == 0 && C == 0)
            break;
        memset(vis,0,sizeof(vis));
        //--------------------//
        /*while(!q.empty())
        {
            q.pop();
        }*/
        //--------------------//
        for(int i = 0;i<L;i++)
        {
            for(int j = 0;j<R;j++)
            {
                scanf("%s",&maze[i][j]);
                for(int k = 0;k<C;k++)
                {
                    if(maze[i][j][k] == 'S')
                    {
                        Begin.x = i;
                        Begin.y = j;
                        Begin.z = k;
                        Begin.time = 0;
                    }
                    if(maze[i][j][k] == 'E')
                    {
                        End.x = i;
                        End.y = j;
                        End.z = k;
                        End.time = 0;
                    }
                }
            }
        }
        int ans = bfs();
        if(ans == -1)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",ans);
        }
    }
}
