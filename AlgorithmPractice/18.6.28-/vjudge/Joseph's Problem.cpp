#include <cstdio>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        long long ans = 0;
        for(int i = 1;i<=n;i++)
        {
            ans += k%i;
        }
        /*int f = 1;
        if(f)
        {
            f = 0;
            printf("%d\n",ans);
        }
        else
        {
            printf("\n%d",ans);
        }*/
        printf("%d",ans);
    }
    return 0;
}
