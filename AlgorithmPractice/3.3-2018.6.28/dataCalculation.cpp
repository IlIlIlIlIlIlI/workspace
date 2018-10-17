#include<stdio.h>

bool check(int x)
{
    if((x % 4 == 0) && ((x % 100 == 0) || (x % 400 == 0)))
        return true;
    return false;
}

int main()
{
    if(y == 2017 && m == 8)
    {
        printf("%d\n",d-16);
        continue;//*******//
    }
    //***********!¾«Ëè!*************//
    int ans = -16;
    while(a < y || b < m)
    {
        ans += mon[b];
        if(b == 2 && check(a))
        {
            ans++;
        }
        b++;
        if(b == 13)
        {
            a++;
            b = 1;
        }
    }
    ans += d;
    printf("%d\n",ans);
    //***********!¾«Ëè!*************//
}
