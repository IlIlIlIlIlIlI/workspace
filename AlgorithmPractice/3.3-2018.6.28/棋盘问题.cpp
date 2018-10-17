#include<stdio.h>
#include<string.h>
#define maxn 1024

int n,k;
int ans,y;
char field[maxn][maxn];
int book[maxn];

void ndfs(int now)
{
    if(k == y)
    {
        ans++;
        return;
    }
    if(now >= n)
        return;
    for(int i = 0;i<n;i++)
    {
        /***************¡ý¡ý¡ý¾«¡ýËè¡ý¡ý¡ý***************/
        if(book[i] == 0 && field[now][i] == '#')
        {
            book[i] = 1;
            y++;
            ndfs(now+1);
            book[i] = 0;
            y--;
        }
        /***************¡ü¡ü¡ü¾«¡üËè¡ü¡ü¡ü***************/
    }
    ndfs(now+1);
}

int main()
{
    while(scanf("%d%d",&n,&k) == 2 && n>= 1 && n <= 8 && k >= 0 && k <= n)
    {
        ans = 0;
        y = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%s",&field[i]);
        }

        memset(book,0,sizeof(book));
        ndfs(0);


        printf("%d\n",ans);
    }
}
