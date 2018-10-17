#include<stdio.h>
#include<string.h>
#define maxn 10010
int a[maxn][maxn];
int main()
{
    int n,x,y;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    int tot=a[x=0][y=n-1] = 1;
    while(tot < n*n)
    {
        while(x+1 < n && !a[x+1][y]) a[++x][y] = ++tot;
        while(y-1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;
        while(x-1 >= 0 && !a[x-1][y]) a[--x][y] = ++tot;
        while(y+1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }
    for(int i = 0;i<n;i++)      //最简单的不一定不是最好的
        {
        for(int j = 0;j<n;j++)
        printf("%4d",a[i][j]);
        printf("\n");
        }
}
