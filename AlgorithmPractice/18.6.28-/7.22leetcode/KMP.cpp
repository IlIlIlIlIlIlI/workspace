#include <cstdio>
#include <string.h>

int* getNext(char ch[])
{
    int next[strlen(ch)];
    next[0] = -1;
    int j = 0,k = -1;
    while(j < strlen(ch)-1)
    {
        if(k == -1 || ch[j] == ch[k])
        {
            next[++j] = ++k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

int kmp(char str1[],char str2[])
{
    int i = 0,j = 0;
    int *next = getNext(str2);
    while(i < strlen(str1) && j < strlen(str2))
    {
        if(j == -1 || str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == strlen(str2))
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char ch1[] = "asglkgfdh vj",ch2[] = "h ";
    printf("%d\n",kmp(ch1,ch2));
    return 0;
}
