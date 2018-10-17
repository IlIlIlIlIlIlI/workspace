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

//����ȫ�ֱ���������
int n,m;

Edge a[maxn];
int fa[maxn];//ÿ����ĸ��ڵ�
int ra[maxn];//?ÿ����Ľ���?

//�Խ��жϺ���
int cmp(const void *a,const void *b)
{
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

//��ʼ����
void init(int n)
{
    for(int i = 0;i<n;i++)
    {
        ra[i] = 0;
        fa[i] = i;
    }
}

//���ҵ�ĸ����
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

//���ֶ�����
        if(fa[x] == x)
            return x;
        else
           finde(fa[x]);
    }

//��������
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

//�������·,������Сֵ
//nΪ�ߣ�mΪ��
int kruskal(int n,int m)
{
    int nEdge = 0;
    int ans = 0;
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i = 0;i<n && nEdge != m-1;i++)
    {
        //�ж�һ���ߵ��������Ƿ�Ϊͬһ����
        if(finde(a[i].a) != finde(a[i].b))
        {
                unite(a[i].a,a[i].b);
                ans += a[i].w;
                nEdge++;
        }
    }
    //�������ѭ����������ıߵ�����С��m-1�������������ͼ����ͨ������������С������
    if(nEdge < m-1)
    {
        ans = -1;
    }
    return ans;
}
int main()
{
    int Ans;
    //n = 0 ʱ�˳�
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
