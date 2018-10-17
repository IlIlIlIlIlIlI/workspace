#include<stdio.h>
#include <math.h>
int main()
    {
           double s,a,b,c,area;

        printf("a=");
        scanf("%lf",&a);

        printf("b=");
        scanf("%lf",&b);

        printf("c=");
        scanf("%lf",&c);


        s=(a+b+c)/2;

        printf("%lf%lf%lf%lf",a,b,c,s);

        area=sqrt(s*(s-a)*(s-b)*(s-c));
            printf("area=%f\n",area);
        return 0;
    }
