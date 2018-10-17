#include<stdio.h>
int main()
{
    for(double i = 0;i!= 10;i+=0.1)
        printf("%.1f\n",i);    //会无穷的执行下去
}                               //因为double永远不等于int

