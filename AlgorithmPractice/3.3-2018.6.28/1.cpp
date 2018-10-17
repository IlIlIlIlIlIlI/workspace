#include<cstdio>
#include<cstdlib>
#include <algorithm>
#define maxn 100005
using namespace std;
int fa[maxn];
struct edge
{
    int x,y,w;
};
edge a[maxn];
bool cmp(const edge &a,const edge &b)
{
    return a.w < a.w;
}
void init(int n)
{
    for(int i = 0;i < n;i++)  fa[i] = i;
}
int Find(int x)
{
    if(fa[x] == x) return x;
    else Find(fa[x]);
}
void unite(int x,int y)
{
    x = Find(x);
    y = Find(y);
    fa[y] = x;
}
int Kruskal(int n,int m)
{
    int tem = 0;
    init(n);
    sort(a+1,a+m+1,cmp);
    for(int i = 1;i <= n;i++)
    {
        if(Find(a[i].x) != Find(a[i].y))
        {
            unite(a[i].x,a[i].y);
            tem += a[i].w;
        }
    }
    return tem;
}
int main()
{
    int n,m,ans;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1;i <= n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
        ans = Kruskal(n,m);
        printf("%d",ans);
    }
    return 0;
}
