#include <cstdio>
int a[100];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l %= (1000000007);
        r %= (1000000007);
        long long ans = 0;
        for(int i = l;i<=r;i++)
        {

            if(i % 7 == 0)
            {
                continue;
            }

            int sum = 0;
            int j = 0,f = 0;
            int ii = i;
            while(ii != 0)
            {
                a[j] = ii%10;
                sum += a[j];

                if(a[j] == 7)
                {
                    f = 1;
                    break;
                }
                j++;
                ii /= 10;
            }
            if((f == 1) || (sum % 7 == 0))
            {
                continue;
            }
            else
            {
                //printf("%d\n",i);

                ans += i*i;
            }
        }

        ans %= 1000000007;
        printf("%lld\n",ans);
    }
    return 0;
}
