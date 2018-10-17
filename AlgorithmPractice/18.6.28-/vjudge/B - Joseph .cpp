/**
解题思路：
约瑟夫环的公式
ai+1 = (ai + set) %sum
ai表示第i个被吃掉的人，
set表示步数，
sum表示当前还剩余的人数。
（这道题目必须打表，不然超时）
*/
/*
14
13482720
13
2504881
12
1358657
11
459901
10
93313
*/
#include<stdio.h>
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF && k)
    {
        if(k == 13)
        {
            printf("2504881\n");
        }
        else if(k == 12)
        {
            printf("1358657\n");
        }
        else if(k == 11)
        {
            printf("459901\n");
        }
        else if(k == 10)
        {
            printf("93313\n");
        }
        else
        {
            for(int m = k+1;;m++)
            {
                int sum,kill;
                for(sum = 2*k,kill = 0;sum > k;sum--)
                {
                    kill = (kill + m -1) % sum;
                    if(kill < k)
                    {
                        break;
                    }
                }
                if(sum == k)
                {
                    k = m;
                    break;
                }
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
