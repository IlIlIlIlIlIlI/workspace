#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len,n;
        scanf("%d%d",&len,&n);
        int maxn = 0,minn = 0;
        for(int i = 0;i<n;i++)
        {
            int disL;
            scanf("%d",&disL);
            maxn = max(maxn,max(disL,len - disL));
            minn = max(minn,min(disL,len - disL));
        }
        printf("%d %d\n",minn,maxn);
    }
    return 0;
}
