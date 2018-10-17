//要特别注意逻辑运算符的短路现象！！！！！！
#include<cstdio>
using namespace std;
char abcd[5] = {0,'A','B','C','D'};
char Array[11];


/**
    int A = 0,B = 0,C = 0,D = 0;
    int Min,Max;
    for(int i = 1;i < 11;i++)
        {
            if(Array[i] == 'A') A++;
            if(Array[i] == 'B') B++;
            if(Array[i] == 'C') C++;
            if(Array[i] == 'D') D++;
        }
    Min = ((((A < B ? A : B) < C) ? (A < B ? A : B) : C) < D) ? (((A < B ? A : B) < C) ? (A < B ? A : B) : C) : D;
    Max = ((((A > B ? A : B) > C) ? (A > B ? A : B) : C) > D) ? (((A > B ? A : B) > C) ? (A > B ? A : B) : C) : D;
*/
bool judge2()
{
    if(Array[2] == 'A')
    if(Array[5] == 'C') return true;
    if(Array[2] == 'B')
    if(Array[5] == 'D') return true;
    if(Array[2] == 'C')
    if(Array[5] == 'A') return true;
    if(Array[2] == 'D')
    if(Array[5] == 'B') return true;
}
//一组加括号
bool judge3()
{
    if(Array[3] == 'A')
    if(Array[3] != Array[6] &&//
       Array[3] != Array[2] &&//
       Array[3] != Array[4] ) return true;
    if(Array[3] == 'B')
    if(Array[6] != Array[3] &&//
       Array[6] != Array[2] &&//
       Array[6] != Array[4] ) return true;
    if(Array[3] == 'C')
        //3and6 exchange
    if(Array[2] != Array[3] &&//
       Array[2] != Array[6] &&//
       Array[2] != Array[4] ) return true;
    if(Array[3] == 'D')
    //623to362
    if(Array[4] != Array[3] &&//
       Array[4] != Array[6] &&//
       Array[4] != Array[2] ) return true;
    else return false;
}
//4.1忘记排他
//4.2加括号
bool judge4()
{
    if(Array[4] == 'A')
    if((Array[1] == Array[5]) &&
       //9107to7910
       ((Array[2] != Array[7]) &&
       (Array[1] != Array[9]) &&
       (Array[6] != Array[10])) ) return true;
    if(Array[4] == 'B')
    if((Array[2] == Array[7]) &&
       //9105to5910
       ((Array[1] != Array[5]) &&
       (Array[1] != Array[9]) &&
       (Array[6] != Array[10])) ) return true;
    if(Array[4] == 'C')
    if((Array[1] == Array[9]) &&
       //5107to7510
       ((Array[2] != Array[7]) &&
       (Array[1] != Array[5]) &&
       (Array[6] != Array[10])) ) return true;
    if(Array[4] == 'D')
    if((Array[6] == Array[10]) &&
       //957to759
       ((Array[1] != Array[5]) &&
       (Array[2] != Array[7]) &&
       (Array[1] != Array[9])) ) return true;
}
//5.忘记排他
bool judge5()
{
    if(Array[5] == 'A')
    if((Array[5] == Array[8]) &&
       ((Array[5] != Array[4]) &&
       (Array[5] != Array[9]) &&
       (Array[5] != Array[7])) ) return true;
    if(Array[5] == 'B')
    if((Array[5] == Array[4]) &&
       ((Array[5] != Array[8]) &&
       (Array[5] != Array[9]) &&
       (Array[5] != Array[7])) ) return true;
    if(Array[5] == 'C')
    if((Array[5] == Array[9]) &&
       ((Array[5] != Array[8]) &&
       (Array[5] != Array[4]) &&
       (Array[5] != Array[7])) ) return true;
    if(Array[5] == 'D')
    if((Array[5] == Array[7]) &&
       ((Array[5] != Array[8]) &&
       //9and8 exchange
       (Array[5] != Array[4]) &&
       (Array[5] != Array[9])) ) return true;
}
//6.1忘记排他
//6.2忘记同型要括号与||
//4to8 mistake
bool judge6()
{
    if(Array[8] == 'A')
        //42to24
    if(((Array[8] == Array[2] &&
       Array[2] == Array[4])) &&
       ((Array[8] != Array[1] ||//
       Array[8] != Array[6]) &&
       (Array[8] != Array[3] ||//
       Array[8] != Array[10]) &&
       (Array[8] != Array[5] ||//
       Array[8] != Array[9])) ) return true;
    if(Array[8] == 'B')
    if(((Array[8] == Array[1] &&
       Array[1] == Array[6])) &&
       //3to2
       ((Array[8] != Array[2] ||//
       Array[8] != Array[4]) &&
       (Array[8] != Array[3] ||//
       Array[8] != Array[10]) &&
       (Array[8] != Array[5] ||//
       Array[8] != Array[9])) ) return true;
    if(Array[8] == 'C')
    if(((Array[8] == Array[3] &&
       Array[3] == Array[10])) &&
       ((Array[8] != Array[1] ||//
       Array[8] != Array[6]) &&
       (Array[8] != Array[4] ||//
       Array[8] != Array[2]) &&
       (Array[8] != Array[5] ||//
       Array[8] != Array[9])) ) return true;
    if(Array[8] == 'D')
    if(((Array[8] == Array[5] &&
       Array[5] == Array[9])) &&
       ((Array[8] != Array[1] ||//
       Array[8] != Array[6]) &&
       (Array[8] != Array[3] ||//
       Array[8] != Array[10]) &&
       (Array[8] != Array[2] ||//
       Array[8] != Array[4])) ) return true;
}
bool judge7()
{
    int A = 0,B = 0,C = 0,D = 0;
    int Min;
    for(int i = 1;i < 11;i++)
        {
            if(Array[i] == 'A') A++;
            if(Array[i] == 'B') B++;
            if(Array[i] == 'C') C++;
            if(Array[i] == 'D') D++;
        }
    Min = ((((A < B ? A : B) < C) ? (A < B ? A : B) : C) < D) ? (((A < B ? A : B) < C) ? (A < B ? A : B) : C) : D;
    if(Array[7] == 'A')
    if(Min == C) return true;
    if(Array[7] == 'B')
    if(Min == B) return true;
    else if(Array[7] == 'C')
    if(Min == A) return true;
    if(Array[7] == 'D')
    if(Min == D) return true;
}
//8.1应使用==。而非！=
//8.2短路......应使用括号把||连接的两个式子括上
bool judge8()
{
    if(Array[8] == 'A')
    {
    if(Array[1] == 'A' && (Array[7] == 'C' || Array[7] == 'D')) {return true;}
    if(Array[1] == 'B' && Array[7] == 'D') {return true;}
    if(Array[1] == 'C' && Array[7] == 'A') {return true;}
    if(Array[1] == 'D' && (Array[7] == 'A'|| Array[7] == 'B')) {return true;}
    }
    if(Array[8] == 'B')
    {
    if(Array[1] == 'A' && (Array[5] == 'C' || Array[5] == 'D')) {return true;}
    if(Array[1] == 'B' && Array[5] == 'D') {return true;}
    if(Array[1] == 'C' && Array[5] == 'A') {return true;}
    if(Array[1] == 'D' && (Array[5] == 'A' || Array[5] == 'B')) {return true;}
    }
    if(Array[8] == 'C')
    {
    if(Array[1] == 'A' && (Array[2] == 'C' || Array[2] == 'D')) {return true;}
    if(Array[1] == 'B' && Array[2] == 'D') {return true;}
    if(Array[1] == 'C' && Array[2] == 'A') {return true;}
    if(Array[1] == 'D' && (Array[2] == 'A' || Array[2] == 'B')) {return true;}
    }
    if(Array[8] == 'D')
    {
    if(Array[1] == 'A' && (Array[10] == 'C' || Array[10] == 'D')) {return true;}
    if(Array[1] == 'B' && Array[10] == 'D') {return true;}
    if(Array[1] == 'C' && Array[10] == 'A') {return true;}
    if(Array[1] == 'D' && (Array[10] == 'A' || Array[10] == 'B')) {return true;}
    }
}
//用错||
bool judge9()
{
    if(Array[9] == 'A')
    {
        if((Array[1] == Array[6]) && (Array[5] != Array[6])) return true;
        if((Array[1] != Array[6]) && (Array[5] == Array[6])) return true;
    }
    if(Array[9] == 'B')
    {
        if((Array[1] == Array[6]) && (Array[5] != Array[10])) return true;
        if((Array[1] != Array[6]) && (Array[5] == Array[10])) return true;
    }
    if(Array[9] == 'C')
    {
        if((Array[1] == Array[6]) && (Array[5] != Array[2])) return true;
        if((Array[1] != Array[6]) && (Array[5] == Array[2])) return true;
    }
    if(Array[9] == 'D')
    {
        if((Array[1] == Array[6]) && (Array[5] != Array[9])) return true;
        if((Array[1] != Array[6]) && (Array[5] == Array[9])) return true;
    }
}
bool judge10()
{
    int A = 0,B = 0,C = 0,D = 0;
    int Min,Max;
    for(int i = 1;i < 11;i++)
        {
            if(Array[i] == 'A') A++;
            if(Array[i] == 'B') B++;
            if(Array[i] == 'C') C++;
            if(Array[i] == 'D') D++;
        }
    Min = ((((A < B ? A : B) < C) ? (A < B ? A : B) : C) < D) ? (((A < B ? A : B) < C) ? (A < B ? A : B) : C) : D;
    Max = ((((A > B ? A : B) > C) ? (A > B ? A : B) : C) > D) ? (((A > B ? A : B) > C) ? (A > B ? A : B) : C) : D;
    if(Array[10] == 'A')
    if((Max - Min) == 3) return true;
    if(Array[10] == 'B')
    if((Max - Min) == 2) return true;
    if(Array[10] == 'C')
    if((Max - Min) == 4) return true;
    if(Array[10] == 'D')
    if((Max - Min) == 1) return true;
}
int main()
{
    for(int i = 1;i < 5;i++)
        for(int j = 1;j < 5;j++)
            for(int k = 1;k < 5;k++)
                for(int l = 1;l < 5;l++)
                    for(int m = 1;m < 5;m++)
                        for(int n = 1;n < 5;n++)
                            for(int o = 1;o < 5;o++)
                                for(int p = 1;p < 5;p++)
                                    for(int q = 1;q < 5;q++)
                                        for(int r = 1;r < 5;r++)
                                        {
                                            Array[1] = abcd[i];
                                            Array[2] = abcd[j];
                                            Array[3] = abcd[k];
                                            Array[4] = abcd[l];
                                            Array[5] = abcd[m];
                                            Array[6] = abcd[n];
                                            Array[7] = abcd[o];
                                            Array[8] = abcd[p];
                                            Array[9] = abcd[q];
                                            Array[10] = abcd[r];
                                            if(!judge2()) continue;
                                            if(!judge3()) continue;
                                            if(!judge4()) continue;
                                            if(!judge5()) continue;
                                            if(!judge6()) continue;
                                            if(!judge7()) continue;
                                            if(!judge8()) continue;
                                            if(!judge9()) continue;
                                            if(!judge10()) continue;
                                            for(int i = 1;i < 11;i++)
                                            printf("%c",Array[i]);
                                        }
                                        return 0;
                                    }

