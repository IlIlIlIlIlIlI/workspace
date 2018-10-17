#include<stdio.h>
int main()
{
    int a,Max,Min,Count = 0;
    scanf("%d",&a);
    Max = a;  Min = a;
    while(a >= 0)
    {
        Max = (Max > a) ? Max : a;
        Min = (Min < a) ? Min : a;
        Count++;
        scanf("%d",&a);
    }
    printf("+---------------------------------------+\n");
    printf("|\tMAX =%d\tMIN =%d\tCount =%d\t|\n",Max,Min,Count);
    printf("+---------------------------------------+");
return 0;
}

