#include <iostream>
using namespace std;
# define	MAXN	100
int	a[MAXN]={0}, res[MAXN] = {0};
int cnt1 = 0, cnt2 = 0;
//递归地找出从自然数1..m中任取k个数的所有组合
//【1】修改void C(int m,int k)使其通过以下测试用例。
void C(int m,int k)
{
  int i,j;
	for (i=m;i>=k;i--)
	{
	  a[k]=i;
		if (k>1) C(i-1,k-1);
		else 
		{
		  for (j=a[0];j>1;j--) cout<<a[j]<<"   ";
          cout << a[j] << endl;
          cnt1++;
		}
	}
}


void main4comb( )
{
  int m=5,k=3;
  cin>>m>>k;
  int x = m, y = k;
  a[0]=k;    // 用来表示k
  C(m,k);
  cout << "C(" << m << "," << k << ")=" << cnt1 << endl;
}

//输出一个正整数n的所有整数和形式。
//k指示当前项的存放位置，还可以表示和的项目数(第一次调用时k=0表示项目数未知)
//【2】修改void S(int n ,int k)使其通过以下测试用例。
//【3】思考如何去除重复的整数和形式，把回答写在注释里。
//【思考】：只输出单调不增的解
/*
void S(int n ,int k)
{	int i;
	if (n>0) {
	  for(i=n; i>=1; i--) {
		if(!k || i <= a[k-1]) {    //判断是否单调不增
          a[k]=i;
		  S(n-i,k+1);
        }
      }
    }    
	else {
        cout << a[0];
	  for (i=1; i<k; i++) cout<<"   "<<a[i];
		cout<<endl;	
        cnt2++;
	}
}
*/

void S(int n ,int k)
{	int i;
	if (n>0)
	  for(i=n; i>=1; i--){
		  a[k]=i;
		  S(n-i,k+1);}
	else {
        cout << a[0];
	  for (i=1; i<k; i++) cout<<"   "<<a[i];
		cout<<endl;	
        cnt2++;
	}
}

void main4sigma()
{
  int n,num;
  cin>>n;
  S(n,0);
  cout << "sigma(" << n << ",0)=" << cnt2;
}

int main()
{
  main4comb();
  main4sigma();
  return 0;
}

/*
void s(int top1, int top2)
{
    if(!top1)   //s1空， 则找到一组解，本次递归结束， 输出s2
    {
        for(int i = 0; i < top2-1; i++)    //输出s2
        {
            cout << res[i] << "   ";
        }
        cout << res[top2-1] << endl;
        cnt2++;
    }
    else
    {
        for(int i = top1; i > 0; i--)    
        {
            if(!top2 || i <= a[top2-1])   
            {    
                res[top2] = i;
                s(top1 - i, top2 + 1);
            }
        }
    }
}
*/
