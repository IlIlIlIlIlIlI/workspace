#include<stdio.h>
#include<algorithm>
#define maxn 1024
//using namespace std;

typedef struct Edge
{
    int a;
    int b;
    int w;
}edge;

//定义全局变量，方便
int n,m;

Edge a[maxn];
int fa[maxn];//每个点的父节点
int ra[maxn];//?每个点的阶数?

//自建判断函数
int cmp(const void *a,const void *b)
{
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

//初始化树
void init(int n)
{
    for(int i = 0;i<n;i++)
    {
        ra[i] = 0;
        fa[i] = i;
    }
}

//查找点的父结点
int finde(int x)
{
/*
    int root = x;
    while(root != fa[root])
    {
        root = fa[root];
    }
    while(x != root)
    {
        int t = fa[x];
        fa[x] = root;
        x = t;
    }
    return root;
}
*/

//两种都可以
        if(fa[x] == x)
            return x;
        else
           finde(fa[x]);
    }

//连结两点
void unite(int x,int y)
{
    x = finde(x);
    y = finde(y);
    if(ra[x] < ra[y])
    {
        fa[x] = y;
    }
    else
    {
        fa[y] = x;
        if(ra[x] == ra[y])
            ra[x]++;
    }
}

//查找最短路,返回最小值
//n为边，m为点
int kruskal(int n,int m)
{
    int nEdge = 0;
    int ans = 0;
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i = 0;i<n && nEdge != m-1;i++)
    {
        //判断一条边的两个点是否为同一棵树
        if(finde(a[i].a) != finde(a[i].b))
        {
                unite(a[i].a,a[i].b);
                ans += a[i].w;
                nEdge++;
        }
    }
    //如果跳出循环，即加入的边的数量小于m-1，则表明改无向图不连通，即不存在最小生成数
    if(nEdge < m-1)
    {
        ans = -1;
    }
    return ans;
}
int main()
{
    int Ans;
    //n = 0 时退出
    while(scanf("%d%d",&n,&m),n)
    {
        init(m);
        for(int i = 0;i<n;i++)
        {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].w);

        }

        Ans = kruskal(n,m);

        if(Ans == -1)
        {
            printf("?\n");
        }
        else
        {
            printf("%d\n",Ans);
        }
    }
    return 0;
}
