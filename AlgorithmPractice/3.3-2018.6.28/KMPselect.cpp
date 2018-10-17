#include<stdio.h>
#include<string.h>
void getNext(char *m,int *next)
{
    int i = 1;//用于next数组的下标
    next[1] = 0;//next数组下标从1开始，故首next元素必为0
    int j = 0;//用于储存回溯值,即next数组元素的值
    while(i<strlen(m))//***!!!不懂!!!***
    {
        //如果j==0，说明判断的是next的第二个元
        //如果m[i-1] == m[j-1]说明当前元素的前一个元素与m[当前元素的前一个元素的next回溯值]相等
        //，则判断结束，当前元素的next值=当前元素的前一个元素的next回溯值+1
        //如果不相等，***！！！不懂！！！***
        if(j == 0 || m[i-1] == m[j-1])
        {
            i++;
            j++;
            //**********************
            //对getNext进行优化

            if(m[i-1]!=m[j-1]) {
               next[i]=j;
            }
            //！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
            //优化处
            //*********************************
            //设存在两个相同的a，a1与a2，若a1与主串不匹配，则a2必不匹配
            //，故没必要再判断，故将使回溯值相同
            //*********************************
            else{
                next[i]=next[j];
            //！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
        }
        //************************
        }else
        {
            j = next[j];//***！！！不懂！！！***
        }

    }
}
int KMP(char* n,char* m)
{
    int next[10];
    getNext(m,next);//根据模式串m，初始化next数组
    int i = 1;//
    int j = 1;
    //开始匹配
    while(i<=strlen(n) && j<=strlen(m))//匹配结束条件为遍历完主串或模式串
    {
        //若j==0，则第一个字符就不匹配
        //若n[i-1] == m[j-1]，则字符匹配，继续匹配
        if(j == 0 || n[i-1] == m[j-1])
            {
                i++;
                j++;
            }
            else j = next[j];//***！！！不懂！！！***
    }
    //若if为真，则匹配成功
    if(j>strlen(m)) return i-(int)strlen(m);//因为初始i=1，故不需再-1
    return -1;//若上述表达式都不成立，则匹配失败，返回-1
}
int main()
{
    int add = KMP("ababcabcabcacbab","abcac");
    printf("%d",add);
}
