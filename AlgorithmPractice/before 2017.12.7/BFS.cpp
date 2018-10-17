#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
char map[25][25];
int vis[25][25];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,m;
int ax,ay;
struct point
{
    int x,y,time;
};
queue<point>q;
bool judge_1(int xx,int yy)
{
    if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&map[xx][yy]!='*')
        return true;
    else
        return false;
}
bool judge_2(int a,int b,int c,int d,int step)
{
  if(judge_1(c,d))
{
    if(map[a][b]=='|')
    {
        if(b==d)
        {
            if(step%2==0)
                return true;
            else
                return false;
        }
        else
        {
            if(step%2==0)
                return false;
            else
                return true;
        }
    }
    else if(map[a][b]=='-')
    {
                if(a==c)
        {
            if(step%2==0)
                return true;
            else
                return false;
        }
        else
        {
            if(step%2==0)
                return false;
            else
                return true;
          }
      }
  }
return false;
}

void bfs()
{
    memset(vis,1,sizeof (vis));
    vis[ax][ay]=1;
    while(!q.empty())
    {
        point temp=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=temp.x+dir[i][0];
            int yy=temp.y+dir[i][1];
            if(judge_1(xx,yy))
            {
                point next;
                next.x=xx;
                next.y=yy;
                next.time=temp.time+1;
                if(map[xx][yy]=='T')
                {
                    printf("%d\n",next.time);
                    return;
                }
                else if(map[xx][yy]=='.')
                {
                    vis[xx][yy]=1;
                    q.push(next);
                }
                else if(map[xx][yy]=='|'||map[xx][yy]=='-')
                {
                    point lou;
                    lou.x=xx+dir[i][0];
                    lou.y=yy+dir[i][1];
                    if(judge_2(xx,yy,lou.x,lou.y,temp.time))
                    {
                        lou.time=temp.time+1;
                        vis[lou.x][lou.y]=1;
                        if(map[lou.x][lou.y]=='T')
                        {
                            printf("%d\n",lou.time);
                            return ;
                        }
                        q.push(lou);
                    }
                else
                {
                    if(judge_1(lou.x,lou.y))
                    {
                        lou.x=temp.x;
                        lou.y=temp.y;
                        lou.time=temp.time+1;
                        vis[lou.x][lou.y]=1;
                        q.push(lou);
                    }
                }
              }
            }
        }
    }
}
int main()
{
    while(!q.empty())
    {
        q.pop();
    memset(map,0,sizeof(map));
    point start;
    for(int i=0;i<n;i++)
    {
        getchar();
        for(int j=0;j<m;j++)
        {
            scanf("%c",&map[i][j]);
            if(map[i][j]=='S')
            {
                ax=i;
                ay=j;
            }
        }
    }
    start.x=ax;
    start.y=ay;
    start.time=0;
    q.push(start);
    bfs();
    }
    return 0;
}



















