#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char a[5005];
int b[5005];
int main()
{
	while(scanf("%s",a)!=EOF)
	{
		memset(b,0,sizeof(b));//记住清零
		int t=0;
		int n=strlen(a);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!='5')//如果不是字符5，直接保存
			{
				b[t]=b[t]*10+(a[i]-'0');
				flag=1;
			}//并且这一句将前导5也给考虑到了，前导是5，直接往后遍历就行了！
			else if(flag==1)//由于害怕有多个字符5相连会多次t++操作，所以要
			{//用一个flag标志来表示这个五前面是否有不是字符5的数，如果有的话
				t++;//才能说明需要再用一个容器来保存下一个数！
				flag=0;//（也就是说排除多个5相连的情况）
			}//遇到字符5，就进行t++，除了多个5相连的情况，只需要加一次
			if(a[i]!='5'&&a[i+1]=='\0')//处理结尾不是字符5的情况！
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
