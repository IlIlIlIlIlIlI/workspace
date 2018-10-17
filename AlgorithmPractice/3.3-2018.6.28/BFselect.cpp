//BF匹配算法
#include<stdio.h>
#include<string.h>
int sel(char* n,char* m)
{
    int i = 0;
    int j = 0;
    while(i<strlen(n) && j<strlen(m))
    {
        if(n[i] == m[j])
        {
            i++;
            j++;
        }
        else
        {
            //匹配失败，记录匹配进度的指针i进行i-j+1的回退动作（指针回溯）
            i = i-j+1;
            j = 0;
        }
    }
        //跳出循环有两种可能
        //1.主串遍历完了
        //2.模式串遍历完成，匹配成功
        if(j == strlen(m))
            return i-strlen(m)+1;
        return 0;  //***不懂***

}
int main()
{
    char a[]={"abcdefhhde"};
    char b[]={"de"};
    int add = sel(a,b);
    printf("%d",add);
}
/*
时间复杂度：
1.O(m),m为模式串的长度，即第一次匹配就成功
2.正常是O(n+m)
3.最坏情况：O(n*m),即00000001和001，匹配到主串的最后一个才知道匹配成功，计算了n*m次
*/
