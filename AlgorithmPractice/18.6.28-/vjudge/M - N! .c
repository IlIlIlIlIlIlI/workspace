#include<stdio.h>
int a[200001];
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int temp,digit,i,j=0;
        a[0]=1;
        digit=1;
        for(i=2;i<=n;i++)
        {
            int num=0;
            for(j=0;j<digit;j++)
            {
                temp=a[j]*i+num;
                a[j]=temp%10;
                num=temp/10;
            }
            while(num)
            {
                a[digit]=num%10;
                num=num/10;
                digit++;
            }
        }
        for(i=digit-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
	return 0;
}
/*Runtime Error(ACCESS_VIOLATION)*/
