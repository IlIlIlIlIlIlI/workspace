#include<stdio.h>
int main()
{
    int fibonacci[21];
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for(int i = 2;i<20;i++)
    {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",fibonacci[n-1]);
    }
    return 0;
}
