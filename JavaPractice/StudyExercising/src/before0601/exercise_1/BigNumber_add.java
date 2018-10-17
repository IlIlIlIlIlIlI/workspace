package before0601.exercise_1;

import java.util.Scanner;

public class BigNumber_add {
/*
大数相加不能直接使用基本的int类型，因为int可以表示的整数有限，不能满足大数的要求。可以使用字符串来表示大数，模拟大数相加的过程。

思路：

　　 1.反转两个字符串，便于从低位到高位相加和最高位的进位导致和的位数增加；

     2.对齐两个字符串，即短字符串的高位用‘0’补齐，便于后面的相加；

     3.把两个正整数相加，一位一位的加并加上进位。
 */
    public static String add(String n1,String n2)
    {
        StringBuffer result = new StringBuffer();

        //1、反转字符串
        n1 = new StringBuffer(n1).reverse().toString();
        n2 = new StringBuffer(n2).reverse().toString();

        int len1 = n1.length();
        int len2 = n1.length();
        int maxLen = len1 > len2 ? len1 : len2;
        boolean nOverFlow = false; //是否越界
        int nTakeOver = 0 ; //溢出数量

        //2.把两个字符串补齐，即短字符串的高位用0补齐
        if(len1 < len2)
        {
            for(int i = len1 ; i < len2 ; i++)
            {
                n1 += "0";
            }
        }
        else if (len1 > len2)
        {
            for(int i = len2 ; i < len1 ; i++)
            {
                n2 += "0";
            }
        }

        //3.把两个正整数相加，一位一位的加并加上进位
        for(int i = 0 ; i < maxLen ; i++)
        {
            int nSum = Integer.parseInt(n1.charAt(i) +"") + Integer.parseInt(n2.charAt(i) +"");

            if(nSum >= 10)
            {
                if(i == (maxLen - 1))
                {
                    nOverFlow  = true;
                }
                nTakeOver = 1;
                result.append(nSum - 10);
            }
            else
            {
                nTakeOver = 0;
                result.append(nSum);
            }
        }

        //如果溢出的话表示位增加了
        if(nOverFlow)
        {
            result.append(nTakeOver);
        }
        return result.reverse().toString();
    }

    public static void main(String[] args) {
        //输入测试数据
        Scanner scan1= new Scanner(System.in);
        Scanner scan2= new Scanner(System.in);
        String str1 = scan1.next();
        String str2 = scan2.next();

        //输出程序运行时间，单位：毫秒
        long startTime = System.currentTimeMillis();   //获取开始时间
        String str = add(str1,str2);  //测试的代码段
        System.out.println(str);
        long endTime = System.currentTimeMillis(); //获取结束时间
        System.out.println("程序运行时间： "+(endTime-startTime)+"ms");
    }
}
