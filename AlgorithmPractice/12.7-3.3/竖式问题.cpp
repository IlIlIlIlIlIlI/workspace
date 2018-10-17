#include<stdio.h>
#include<string.h>
int main()
{
    int count=0;
    char a[20],b[99];
    scanf("%s",a);
    for(int abc=111;abc<=999;abc++)
        for(int de=11;de<=99;de++)
    {
        int x=abc*(de%10);
        int y=abc*(de/10);
        int z=abc*de;
        sprintf(b,"%d%d%d%d%d",abc,de,x,y,z);
        int ok=1;
        for(int i=0;i<strlen(b);i++)
            if(strchr(a,b[i])==NULL)  ok=0;
        if(ok){
            printf("\t<%d>\n",++count);
            printf("\t%5d\n\tX%4d\n\t-----\n\t%5d\n\t%4d\n\t-----\n\t%5d\n\n",abc,de,x,y,z);
        }
    }
    printf("%d",count);
    return 0;
}
