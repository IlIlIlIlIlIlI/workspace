#include<stdio.h>
#define maxn 1010
int main()
{
    int a[maxn],b[maxn];
    int kase = 0;
    int n;
    int A = 0,B = 0;
    while(scanf("%d",&n) == 1 && n )
    {
        printf("Game %d ",++kase);
        for(int i = 0;i<n;i++) scanf("%d",&a[i]);
        for(;;)
        {
            for(int i = 0;i<n;i++)
            {
                scanf("%d",&b[i]);
                if(a[i] == b[i]) A++;
            }
            if(b[0] == 0) break;
            for(int i = 1;i <= 9;i++)
            {
                int x = 0,y = 0;
                for(int j = 0;j < n;j++)
                {
                    if(a[j] == i) x++;
                    if(b[j] == i) y++;
                }
                if(x < y) B += x;
                else B += y;
            }
            printf("(%d %d)",A,B-A);
        }
    }
}
