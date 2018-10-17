#include<stdio.h>
#include<string.h>
int main()
{
    int a[20][20];
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            a[i][j] = j;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 400; i++)
    {
        ++cnt;
        printf("%d\n",*(a+i*4));
    }
    printf("%d\n",cnt);
    return 0;
}
