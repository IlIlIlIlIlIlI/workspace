#include<stdio.h>
int main()
{
int i,j,k;
    for(i=1;i<=9;i++)
{
 for(j=1;j<=5-i;j++)
{    if(j>=4){printf(" ");j--;}
       printf("\n");
}
 for(k=1;k<=2*i-1;k++)
{   if(k>=7){printf("*");k--;}
    printf("*");
    printf("\n");
}
}
    return 0;
}
