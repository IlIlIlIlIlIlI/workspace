#include<stdio.h>
int a[25][25];
int main()
{
    a[0][0] = 3;
    a[1][0] = 7;
    for(int i = 1;i<=21;i++)
    {
        a[0][i] = 2*(i+1)+1;
        a[1][i] = a[1][i-1]+10+(i-1)*4;
    }

    int n;
    scanf("%d",&n);
    getchar();
    char m;
    scanf("%c",&m);
    if(n>0)
    {
        if(n < 7)   //边界条件要注意！！！！！！！！！！
        {
            printf("%c\n",m);
            printf("%d",n-1);
        }
        else
        {
            int j = 0;
            int tem = n;
            int tag = 3;
            while(n>a[1][j])
            {
                tag = a[0][j];
                tem = a[1][j];
                j++;
            }
            int tag2 = tag;
            int rest = n-tem;

            int lab = tag;
            int num = 3;
            for(int i = 0;i<lab;i++)
            {
                if(tag>0)
                {
                    for(int l = 0;l<i;l++)
                    {
                        printf(" ");
                    }
                    for(int k = 0;k<tag;k++)
                    {
                        printf("%c",m);
                    }
                    printf("\n");
                    tag -= 2;
                }
                else
                {
                   for(int p = 0;p<((tag2-num) / 2);p++)
                   {
                       printf(" ");
                   }
                    for(int g = 0;g<num;g++)
                    {
                        printf("%c",m);
                    }
                    printf("\n");
                    num +=2;
                }
            }
        printf("%d",rest);
    }
    }
}

/**

***************************************
***************************************

7 *
***
 *
***
0

7 *
***
 *
***
0
*/

