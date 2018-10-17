#include<stdio.h>
int main()
{
    int Array[] = {1,1,2,3,4,5,6};
    int A,B,C,D;
    A=B=C=D = 0;
    for(int i = 0;i < 7;i++)
    {
        if(Array[i] == 1) A++;
        if(Array[i] == 2) B++;
        if(Array[i] == 3) C++;
        if(Array[i] == 4) D++;
    }
    int Ma = ((((A > B ? A : B) > C) ? (A > B ? A : B) : C) > D) ? (((A > B ? A : B) > C) ? (A > B ? A : B) : C) : D;
    printf("%d",Ma);
    return 0;
}



