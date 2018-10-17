#include<stdio.h>
int main()
{
    int a=219;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            if((i+j)%2==0)
            printf("%c%c",a,a);
        else
            printf(" ");
        printf("\n");
    }
    return 0;
}
