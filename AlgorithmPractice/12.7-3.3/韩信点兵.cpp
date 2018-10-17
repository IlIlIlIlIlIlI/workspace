//这题真不会......
#include<stdio.h>
int main()
{
    int a,b,c,kcase=0;
    while(scanf("%d%d%d",&a,&b,&c)==1 && a>0 && a<=3 && b>0 && b<=5 && c>0 && c<=7)
    {
        for(int i=0;;i++)
        {
            int x=3*i+a;
            int y=5*i+b;
            int z=7*i+b;
            while(x==y==z && x>10 && x<100)
            {
                ++kcase;
                printf("Case %d: %d",kcase,x);
            }
        }
    }
        ++kcase;
        printf("Case %d:No answer",kcase);
    return 0;
}
