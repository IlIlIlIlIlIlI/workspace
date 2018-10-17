#include<stdio.h>
#include<string.h>
int a[20][20]={0};
int main()
{
    int n,x,y,tot=1;
    scanf("%d",&n);
    a[x=0][y=n-1]=1;
    while(tot<n*n)
    {
        while(x<n-1 && !a[x+1][y])  a[++x][y]=++tot;
        while(y>0 && !a[x][y-1])  a[x][--y]=++tot;
        while(x>0 && !a[x-1][y])  a[--x][y]=++tot;
        while(y<n-1 && !a[x][y+1])  a[x][++y]=++tot;
    }
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
            printf("%3d",a[x][y]);
        printf("\n");
    }
    return 0;
}
