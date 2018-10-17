#include<stdio.h>
int i,j,t;
char a[6];
void MPsort()
{
    for(j=0;j<5;j++)
    {
      for(i=0;i<5-j;i++)
      {
        if(a[i]>a[i+1])
          {t=a[i];a[i]=a[i+1];a[i+1]=t;}
      }
    }
}
void main()
{
     for(i=0;i<6;i++)
      scanf("%c",&a[i]);
          for(i=0;i<6;i++)
        printf("%c ",a[i]);
        printf("\n\n");
    MPsort(a[6]);
          for(i=0;i<6;i++)
        printf("%c ",a[i]);
}

