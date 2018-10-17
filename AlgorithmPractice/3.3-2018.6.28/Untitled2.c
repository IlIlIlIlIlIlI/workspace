#include<stdio.h>
#include<string.h>
void Next(char* m,int* next)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i<strlen(m))
    {
        if(j == 0 || m[i-1] == m[j-1])
        {
            i++;
            j++;
            if(m[i-1] != m[j-1])
            {
                next[i] = j;
            }else{
                next[i] = next[j];
            }
        }else{
             j = next[j];
        }
    }
}
int KMP(char* n,char* m)
{
    int next[10];
    Next(m,next);
    int i = 1;
    int j = 1;
    while(i<=strlen(n) && j<=strlen(m))
    {
        if(j == 0 || n[i-1] == m[j-1])
        {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j>strlen(m)) return i-(int)strlen(m);
    return -1;
}
int main()
{
    int add = KMP("asfdkjsdfhiusd","us");
    printf("%d",add);
}
