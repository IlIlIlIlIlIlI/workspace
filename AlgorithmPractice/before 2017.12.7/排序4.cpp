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
		memset(b,0,sizeof(b));//��ס����
		int t=0;
		int n=strlen(a);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!='5')//��������ַ�5��ֱ�ӱ���
			{
				b[t]=b[t]*10+(a[i]-'0');
				flag=1;
			}//������һ�佫ǰ��5Ҳ�����ǵ��ˣ�ǰ����5��ֱ��������������ˣ�
			else if(flag==1)//���ں����ж���ַ�5��������t++����������Ҫ
			{//��һ��flag��־����ʾ�����ǰ���Ƿ��в����ַ�5����������еĻ�
				t++;//����˵����Ҫ����һ��������������һ������
				flag=0;//��Ҳ����˵�ų����5�����������
			}//�����ַ�5���ͽ���t++�����˶��5�����������ֻ��Ҫ��һ��
			if(a[i]!='5'&&a[i+1]=='\0')//�����β�����ַ�5�������
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
