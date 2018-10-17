#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    while(a<1e6 && b<1e6 && c<=100)
    {
        if(a==0 && b==0 && c==0)  break;
        //先打印‘.’前的数字
        printf("%d.",a/b);
        //再取出‘.’后的数字，放入a
        a%=b;
        for(int i=1;i<=c-1;i++)
        {
            a*=10;
            printf("%d",a/b);
            a%=b;
        }
        int more = ((a*10)%b * 10) / b; //观察第c位的后一位
        if (more >= 5)
            printf("%d\n", (a*10)/b + 1);
        else printf("%d\n", (a*10)/b);
        scanf("%d%d%d",&a,&b,&c);
    }
    return 0;
}

