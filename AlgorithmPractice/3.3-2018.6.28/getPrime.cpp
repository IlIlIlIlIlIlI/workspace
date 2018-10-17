#include<stdio.h>
#include<math.h>
#define maxn 1000000000
void getPrime(int n)
{
    int cnt = 0;
    bool big[maxn+1];
    int sl = 2*3*5*7*11*13*17*19;
    bool small[sl+1];
    int i;
    for(i = 2;i <= sl;i += 2)small[i] = true;
    for(i = 3;i <= sl;i += 3)small[i] = true;
    for(i = 5;i <= sl;i += 5)small[i] = true;
    for(i = 7;i <= sl;i += 7)small[i] = true;
    for(i = 11;i <= sl;i += 11)small[i] = true;
    for(i = 13;i <= sl;i += 13)small[i] = true;
    for(i = 17;i <= sl;i += 17)small[i] = true;
    for(i = 19;i <= sl;i += 19)small[i] = true;
    int remainder = n % sl;
    int p = 1;
    int q = p + n - remainder;
    while(p < q)
    {

    }
    if(remainder > 0)

    big[2] = false;
    big[3] = false;
    big[5] = false;
    big[7] = false;
    big[11] = false;
    big[13] = false;
    big[17] = false;
    big[19] = false;
    int Sqrt = (int )sqrt(n);
    int step,j;
    Sqrt -= 2;
    for()
}
int main()
{

}
