#include <cstdio>

int main()
{
    int k;
    while(scanf("%d",&k) == 1)
    {
        if(++k % 2)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
