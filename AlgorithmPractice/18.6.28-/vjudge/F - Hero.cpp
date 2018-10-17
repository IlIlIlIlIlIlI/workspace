#include <cstdio>
#include <algorithm>
using namespace std;

struct enemy
{
    int dps;
    int hp;
}a[25];

bool cmp(enemy e,enemy ee)
{
    return ee.dps*e.hp < e.dps*ee.hp;

}

int main()
{
    int t;
    while(scanf("%d",&t) == 1)
    {
        int sum = 0;
        for(int i = 0;i<t;i++)
        {
            scanf("%d%d",&a[i].dps,&a[i].hp);
            sum += a[i].dps;
        }
        sort(a,a+t,cmp);
        int ans = 0;
        for(int i = 0;i<t;i++)
        {
            ans += sum*a[i].hp;
            sum -= a[i].dps;
        }
        printf("%d\n",ans);
    }
    return 0;
}


















#include <cstdio>
#include <algorithm>
using namespace std;

struct Enemy
{
    int dps;
    int hp;
}a[30];

bool cmp(Enemy e,Enemy ee)
{
    return ee.hp*e.dps > e.hp*ee.dps;
}

int main()
{
    int t;
    while(scanf("%d",&t) == 1)
    {
        int sum = 0,ans = 0;
        for(int i = 0;i<t;i++)
        {
            scanf("%d%d",&a[i].dps,&a[i].hp);
            sum += a[i].dps;
        }
        sort(a,a+t,cmp);
        for(int i = 0;i<t;i++)
        {
            ans += sum*a[i].hp;
            sum -= a[i].dps;
        }
        printf("%d\n",ans);
    }

    return 0;
}
