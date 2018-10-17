#include <stdio.h>
#define N 10
int i, j, temp, pos, m, n;
int a[1000000];
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
	for (i = 0; i < m; i++)
	{
		temp = a[i];tfh cbcv
		pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (temp < a[j])
			{
				temp = a[j];
				pos = j;
			}
		}
		a[pos] = a[i];
		a[i] = temp;
	}
	for (i = 0; i < m; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
