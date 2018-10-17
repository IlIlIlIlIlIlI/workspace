#include<stdio.h>
#define INF 1000000
int main()
{
    int n,m;
    double sum=0;
    scanf("%d%d",&n,&m);
    while(m<INF && n<=m)
    {
        if(n==0 && m==0)  break;
        for(;n<=m;n++)
        {
            //对于取证运算“/”，如果要化为小数的话，分子或分母应为浮点数形式
            double x=(1.0/n)*(1.0/n);
            sum+=x;
        }
        printf("%.5f",sum);
        scanf("%d%d",&n,&m);
    }
    return 0;
}

