//很简单的一道题，周赛的时候wrong了3次。。。。。。。。。。打击打击。。。。纪念下
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char s[100000000];
    int a[100000000];
    int i,len,k,n;
    while(scanf("%s",s)!=EOF)
    {
        n=0;
        k=0;
        len=strlen(s);
        s[len]='5';
        i=0;
        while(s[i++]=='5');  //跳过前缀5,防止多输出0
        for(i--;i<=len;++i)
        {
            if(i>0&&s[i]=='5'&&s[i-1]=='5') //忽略连续的5，防止多输出0
                continue;
            if(s[i]!='5')
                k=k*10+s[i]-'0';
            else            //遇到5就增加一个数
            {
                a[n++]=k;
                k=0;
            }
        }
        sort(a,a+n);
        printf("%d",a[0]);
        for(i=1;i<n;++i)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
