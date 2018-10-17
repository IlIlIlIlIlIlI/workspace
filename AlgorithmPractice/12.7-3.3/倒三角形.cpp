#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        //因为倒三角形的整块图形是左右对称的
        //所以在算出了左侧的空格数后，就不用管右边的空格输出了
        //直接输出“\n”
        for(int j=1;j<=2*n-i;j++)
            {
                if(j<i)  printf(" ");
                else     printf("*");
            }
            printf("\n");
    }
    return 0;
}
