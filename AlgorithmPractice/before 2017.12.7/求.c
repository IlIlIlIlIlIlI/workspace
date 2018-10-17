#include<stdio.h>
#include <math.h>
int main()
    {
            double s,a,b,c,area;

        scanf("%f%f%f",&a,&b,&c);

        s=(a+b+c)/2;

        area=sqrt(s*(s-a)*(s-b)*(s-c));

            printf("area=%f\n",area);

        return 0;
    }
