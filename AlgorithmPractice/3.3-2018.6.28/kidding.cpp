#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1024];
    scanf("%s",&ch);
    getchar();
    int len = strlen(ch);
    if(len >=1 && len <= 100)
    {
        if((len % 2) == 0)
        {
            for(int i = 0;i<len;i += 2)
                {
                    if(i == len-3)printf("%c%c",ch[i],ch[i+1]);
                    else printf("%c%c ",ch[i],ch[i+1]);
                }
        }
        else
        {
            for(int j = 0 ;j<len;j++)
                {
                    if(j == len-1)printf("%c",ch[j]);
                    else printf("%c ",ch[j]);
                }
        }
    }
    return 0;
}

