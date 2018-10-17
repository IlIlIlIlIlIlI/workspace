#include<stdio.h>
//#include<queue>
//using namespace std;

int maze[5][5];

struct node
{
    int x,y,pre;
}q[100];

//queue <node> que;

void output(int i)
{
    if(q[i].pre != -1)
    {
        output(q[i].pre);
        printf("(%d, %d)\n",q[i].x,q[i].y);
    }
}

void bfs(int x,int y)
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int front = 0;
    int rear = 1;
    q[front].x = x;
    q[front].y = y;
    q[front].pre = -1;
    //que.push(q[front]);
    while(front < rear)
    {
        for(int i = 0;i<4;i++)
        {
            int nx = q[front].x + dx[i];
            int ny = q[front].y + dy[i];
            //if(nx >= 0 && nx < 5 && ny >= 0  && ny <5 && maze[nx][ny])
            if(nx<0||nx>=5||ny<0||ny>=5||maze[nx][ny])
                continue;
            else
            {
                maze[nx][ny] = 1;
                q[rear].x = nx;
                q[rear].y = ny;
                q[rear].pre = front;
                //que.push(q.[rear]);
                rear++;
            }
            if(nx == 4 && ny == 4)
            {
                output(front);
            }
        }
        front++;
    }
}
int main()
{
    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    printf("(0, 0)\n");
    bfs(0,0);
    printf("(4, 4)\n");
}
