
#include<cstdio>
#include<cmath>
using namespace std;
bool judge(int n)
{
	if(n<=1) return false;
	int sqrtN=sqrt(1.0*n);
	for(int i=2;i<=sqrtN;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(judge(i)&&judge(i-2))
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
