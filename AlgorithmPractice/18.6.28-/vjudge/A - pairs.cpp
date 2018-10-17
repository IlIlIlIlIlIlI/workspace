#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;
int a[maxn];
int n,k;

int f(int l,int r,int target)
{
    int mid,ans = 0;
    while(l <= r && r < n)
    {
        mid = (l+r)/2;
        if(a[mid] <= target)
        {
            ans += mid-l+1;
            l = mid +1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);

        long long cnt = 0;
        for(int i = 0;i<n;i++)
        {
            cnt += f(i+1,n-1,a[i]+k);
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
