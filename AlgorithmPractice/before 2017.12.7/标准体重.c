#include<stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
    float x,y;
    printf("enter value of x:");
    scanf("%f",&x);
    y=0.009554*x*x-2.464*x+203.6;
    printf("%f\n",y);
    }
    return 0;
}
