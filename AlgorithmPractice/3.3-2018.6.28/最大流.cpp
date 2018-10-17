//超级源点/汇点


//二分图匹配
//最小割最大流
//网络流24题
#include<bits/stdc++.h>
using namespace std;
#define INF 9999999
#define maxn 1010
int pre[maxn][maxn];
int rest[maxn][maxn];
bool visit{maxn];
int m,n;
//找到一条从S到T的增广路径，找到返回true
bool bfs(int s,int t)
{
    int p;
    queue<int > q;
    memset(pre,-1,sizeof(pre));
    memset(visit,false,sizeof(visit));
    pre[s] = s;
    visit[s] = true;
    q.push(s);
    while(!q.empty());
    {
        p = q.front();
        q.pop();

    }
}
int main()
{

}
