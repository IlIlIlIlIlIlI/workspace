#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char ch[100];
        scanf("%s",ch);
        getchar();
        int cnt = 0;
        char Stack[100];
        int top = -1;
        int book = 0;

        for(int i = 0;i<strlen(ch);i++)
        {
                if(ch[i] == '(' || ch[i] == '[')
                {
                    Stack[++top] = ch[i];
                }
                if(ch[i] == ')' || ch[i] == ']')
                {
                    book++;
                    for(int j = top;j>=0;j--)
                    {
                        char e = Stack[j];
                        if((ch[i] == ')' && e == '(') || (ch[i] == ']' && e == '['))
                        {
                            top--;
                            cnt++;
                            break;
                        }
                    }
                }
        }
        printf("%d\n",2*cnt);
        /*if(top == -1 && cnt == book)
           {
                printf("Yes\n");
           }
            else
            {
                printf("No\n");
            }*/
    }
    return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char *base;
    char *top;
    int stackSize = 100;
}Stack;

void check()
{
        Stack s;
        s.base = (char*)malloc(s.stackSize*sizeof(char));
        s.top = s.base;

        char ch[s.stackSize],*p,e;
        scanf("%s",ch);
        p = ch;
        while(*p)
        {
            switch(*p)
            {
            case '(':
            case '[':
                   {
                       *s.top++ = *p++;//push
                       break;
                   }
            case ')':
            case ']':
                if(s.top != s.base)
                {
                    e = *--s.top;//pop
                    if(*p == ')' && e == '(' || *p == ']' && e == '[')
                    {
                        printf("No\n");
                        return;
                    }
                    else
                    {
                        p++;
                        break;
                    }
                }
                else
                {
                    printf("No\n");
                    return;
                }
            default:
                p++;
            }
        }
        if(s.top == s.base)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        check();
    }
}*/
