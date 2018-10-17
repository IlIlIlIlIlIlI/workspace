#include<stdio.h>
int main()
{
    char a[100];
    int i;
    for(i=0;i<2;i++)
    scanf("%s",&a[i]);
    printf("%s",a[0]);
//若输出a+1，则从第一个数组元素的
//第二个字符出开始打印，至此元素结束
//无论使用的输入函数是啥gets或scanf

//输入时以空格来隔开每个字符串数组元素
    return 0;
}
