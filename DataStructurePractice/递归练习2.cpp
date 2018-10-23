#include <iostream>
#include <sstream>
using namespace std;
# define	MAXN	100
int	a[MAXN]={0};

//HCF - Highest Common Factor 最大公因子
//GCD - Greatest Commnond Divider最大公约数 - Algorithm 1: 
//try all integers from n down until finding one that divides m and n evenly.
int gcdGuess(int m, int n, int g) {
    
  return 1;
}

void main4gcd1()
{
	int m,n;
	cin>>m>>n;
	cout<<"gcd("<<m<<", "<<n<<")"<<endl;
	cout<<gcdGuess(m, n, n)<<endl;
}

//GCD Algorithm 2: Euclid's Algorithm
//If m > n, the gcd of m and n is the same as the gcd of n and m % n.
int gcd2(int m, int n) {


  return 1;
}

void main4gcd2()
{
	int m,n;
	cin>>m>>n;
	cout<<"gcd("<<m<<", "<<n<<")"<<endl;
	cout<<gcd2(m, n)<<endl;
}

//GCD Algorithm 3: Dijkstra's Algorithm
//The idea: If m>n, GCD(m,n) is the same as GCD(m-n,n).
int gcd3(int m, int n) {
  int gcd=1;

  return gcd;
}

void main4gcd3()
{
	int m,n;
	cin>>m>>n;
	cout<<"gcd("<<m<<", "<<n<<")"<<endl;
	cout<<gcd3(m, n)<<endl;
}
//从键盘输入一组自然数
void KeyInput(int num[], int &n, int &max) 
{
	int i = 0;
	max = 1;
	string line, word; 
	getline(cin, line);
	stringstream ss(line);
	while (getline(ss, word, ' ') && i < MAXN)
	{
		num[i++] = stoi(word);
		if (num[i-1] > max) max = num[i-1];
	}
	n = i;
}


////递归地计算一组数的GCD
//n代表num[]的长度(即包含几个数)，max是其中的最大值
int GCDs(int num[], int n, int max)
{
	int gcd = 1;

	return gcd;
}

//LCM - Lowest/Least Common Multiple最小公倍数
//计算一组数的LCM
//n代表num[]的长度(即包含几个数)，max是其中的最大值
int LCMs(int num[], int n, int max)
{
	int lcm = 1;
	
	return lcm;
}

void main4gcd_lcm()
{	int n, max;
	KeyInput(a, n, max);
	cout<<n<<",<="<<max<<endl;
	cout<<GCDs(a, n, max)<<endl;
	cout<<LCMs(a, n, max)<<endl;
}

int main()
{
	main4gcd1();
	//main4gcd_lcm();
	return 0;
}
