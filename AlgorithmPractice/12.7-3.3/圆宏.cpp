#include<stdio.h>
#define PI 3.1415
#define CIRCLE(R,ROUND,AREA) ROUND = 2*PI*R; AREA = PI*R*R;

int main()
{
    int a;
    scanf("%d",&a);
    float round,area;
    CIRCLE(a,round,area)
    printf("\n%6.3f\t %6.3f\n",round,area);
    return 0;
}
