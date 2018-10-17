#include <cstdio>
#include <cmath>
#define PI 3.1415926

int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d) == 2)
    {
        double ans = 0;
        int ang;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&ang);
            ans += 0.5*d*d*sin(ang/180.0*PI);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
