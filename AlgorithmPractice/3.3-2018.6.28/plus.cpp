#include<stdio.h>
#include<string.h>
#define maxn 1024
void add(char* big,char* small)
{
    char temp1[maxn],temp2[maxn],sum[maxn];
    int len1 = strlen(big);
    int len2 = strlen(small);

    //反转入库
    int j = 0;
    for(int i = len1-1;i>=0;--i)
    {
        temp1[j++] = big[i];
    }
    //temp1[j] = '\0';

    j = 0;
    for(int i = len2-1;i>=0;--i)
    {
        temp2[j++] = small[i];
    }

    //补齐small
    for(int i = len2;i<len1;i++)
    {
        temp2[i] = '0';
        //temp2[len1] = '\0';
    }

    //按位相加
    int aSum;
    int overFlow = 0;
    int carryBit = 0;
    for(int i = 0;i<len1;i++)
    {
        aSum = temp1[i] - '0' + temp2[i] - '0' + carryBit;//字符减去‘0’得到数字
        if(aSum>9)
        {
            //先判断是否将要overFloat
            if(i == (len1-1))
            {
                overFlow = 1;
            }
            carryBit = 1;
            sum[i] = aSum - 10 + '0';
        }else{
            sum[i] = aSum + '0';
        }
    }

    //判断是否溢出
    if(overFlow == 1)
    {
        sum[len1++] = carryBit + '0';
    }
    //sum[len1] = '\0';
    for(int i = len1-1;i>=0;i--)
        putchar(sum[i]);
}
int main()
{
    char str1[maxn],str2[maxn];
    gets(str1);
    gets(str2);
    add(str1,str2);
}
