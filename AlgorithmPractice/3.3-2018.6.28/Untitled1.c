#include<stdio.h>
int main()
{
    int Min;
    int f[5];
    int g[5];
    int a[5] = {12,7,9,7,9};
    int b[5] = {8,9,6,6,6};
    int c[5] = {7,17,12,14,12};
    int d[5] = {15,14,6,6,10};
    int e[5] = {4,10,7,10,6};
    for(int i = 0;i<4;i++)
    for(int j = 0;j<4;j++)
    for(int k = 0;k<4;k++)
    for(int l = 0;l<4;l++)
    for(int m = 0;m<4;m++)
    {
        Min = (a[i]+b[j]+c[k]+d[l]+e[m]) < (a[i+1]+b[j+1]+c[k+1]+d[l+1]+e[m+1]) ? (a[i]+b[j]+c[k]+d[l]+e[m]) : (a[i+1]+b[j+1]+c[k+1]+d[l+1]+e[m+1]);
        f[0] = a[i];
        f[1] = b[j];
        f[2] = c[k];
        f[3] = d[l];
        f[4] = e[m];

    }
    printf("*************************\n");
    printf("*******optimizal********\n");
    for(int i = 0;i<5;i++)
        printf("%d ",f[i]);
        printf("\n");
    printf("The miniumn is: %d",Min);
}
