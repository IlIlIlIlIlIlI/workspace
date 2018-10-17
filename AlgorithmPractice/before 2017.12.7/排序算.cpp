#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[5005];
int b[5005];
int main()
{
	while(scanf("%s",a)!=EOF)
	{
		memset(b,0,sizeof(b));
		int t=0;
		int len=strlen(a);
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]!='5')
			{
				b[t]=b[t]*10+(a[i]-'0');
				flag=1;
			}
			else if(flag==1)
			{
				t++;
				flag=0;
			}
			if(a[i]!='5'&&a[i+1]=='\0')
			{
				t++;
			}
		}
		sort(b,b+t);
		for(int i=0;i<t-1;i++)
		{
			printf("%d ",b[i]);
		}
		printf("%d\n",b[t-1]);
	}
	return 0;
}
