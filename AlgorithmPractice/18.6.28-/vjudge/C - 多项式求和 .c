#include <stdio.h>
int main()
{
    int m, n, i;
    double sum;
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &n);
        sum = 0.0;
        for(i=1; i<=n; i++)
        {
            //printf("%d\n",i % 2);
            if(i % 2 == 0)
            {
                sum -= ((double)1.0) / i;
            }
            else
            {
                sum += ((double)1.0) / i;
            }
        }
        printf("%.2f\n", sum);
    }
}
