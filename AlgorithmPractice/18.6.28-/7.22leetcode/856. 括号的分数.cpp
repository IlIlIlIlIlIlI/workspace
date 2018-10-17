class Solution {
public:
    int scoreOfParentheses(string S) {
        int len=S.size(),sum=0;
        int temp=0;
        stack <char> stk;
        for(int i=0;i<len;++i){
             if(!stk.empty()){
                if(S[i]-stk.top()==1){
                stk.pop();
                if(stk.size()>=temp)
                    sum+=pow(2,stk.size());
                temp=stk.size();
                continue;
                }
            }
            stk.push(S[i]);
        }
        return sum;
    }
};



class Solution {
public:
    int scoreOfParentheses(string S) {
        int sum=0;
        stack<int> K;
        for(int i=0;i<S.length();i++)
        {
            switch(S[i])
            {
                case '(':
                    K.push(S[i]);
                    break;
                case ')':
                    if(K.top()=='(')
                    {
                        K.pop();
                        K.push(1);
                    }
                    else
                    {
                        int a=0;
                        while(K.top()!='('&&!K.empty())
                        {
                            a+=K.top();
                            K.pop();
                        }
                        if(K.top()=='(')
                        {
                            int b=2*a;
                            K.pop();
                            K.push(b);
                        }
                        else
                        {
                            K.push(a);
                        }
                    }
                    break;
            }
        }
        while(!K.empty())
	    {
		    sum+=K.top();
		    K.pop();
	    }
        return sum;
    }
};



#include <cstdio>
#include <cstdlib>
#include <string.h>
int scoreOfParentheses(char* S) {
    char ch[55];
    int score[50];
    int sc = -1;
    int book[55];
    int top = -1;
    int num[50],nu = -1,ans = 0;
    memset(book,0,55*sizeof(int));
    memset(num,0,50*sizeof(int));
    while(*S)
    {
        if(*S == '(')
        {
            ch[++top] = *S++;
            if(top >= 1 && book[top-1] != 1 && ch[top-1] == '(')
            {
                book[top-1] = 1;
                num = 0;
            }
        }
        else
        {
            char tmp = *S;
            if(ch[top] == '(' && tmp == ')')
            {
                if(!book[top])
                {
                    score[++sc] = 1;
                    num[++nu]++;
                    top--;
                    S++;
                }
                else
                {
                    //if(num != 0)
                    //{
                        int tmp = 0;
                        for(int i = 0;i<num;i++)
                        {
                            tmp += score[sc];
                            sc--;
                        }
                        score[++sc] = 2*tmp;
                        num = 0;
                    //}
                    book[top] = 0;
                    top--;
                    S++;
                }
            }
        }
    }
    for(int i = 0;i<=sc;i++)
    {
         ans += score[i];
    }
    return ans;
}

int main()
{
    char *s = (char*)malloc(sizeof(char)*10);
    s = "(()())";
    scoreOfParentheses(s);
}
