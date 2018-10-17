#include<stdio.h>
#include<math.h>
int check(int n)
{
    if(n<2)
    {
        return 0;
    }
    int sqrtN = sqrt(n);
    for(int i = 2;i<=sqrtN;i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,cnt = 0;
    scanf("%d",&n);
    for(int i = 2;i<=n;i++)
    {
        if(check(i-2) && check(i))
        {
            cnt++;
        }
    }
    printf("%d",cnt);
}
