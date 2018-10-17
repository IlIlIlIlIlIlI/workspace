package test;

import org.jetbrains.annotations.Contract;

import java.util.Scanner;

public class Determinant {
    //main 输入与输出
    public static void main(String[] args) {
        int n;
        int result;
        Scanner sr = new Scanner(System.in);
        System.out.println("***请输入行列式的阶数：***");
        n = sr.nextInt();
        System.out.println("***请输入行列式的值：***");
        int[] a = new int[n * n];
        for (int j = 0; j < n * n; j++) {
            a[j] = sr.nextInt();
        }
        //调用函数计算行列数
        try {
            result = det(a, 0, n - 1);
            System.out.println(result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //*****************************
    //交换数
    public static void swap(int i, int j) {
        int temp;
        temp = i;
        i = j;
        j = temp;
    }

    //*****************************
    //求逆序数，判断正负
    @Contract(pure = true)
    public static boolean sa(int[] l, int a) {
        int temp = 1;
        // TODO 完善函数

        // 计算在行列式计算过程中每一项前边的符号是正还是负
        int n = 0; // n为行列式展开式每一项的逆序数
        for (int i = 0; i < a - 1; i++)
            for (int j = i + 1; j < a; j++)
                if (l[i] > l[j]) n++; // 不断通过条件判断累加逆序数得出最终的逆序数
        if (n % 2 == 0) return false; // 若为正，则返回false
        return true;    // 否则返回true
    }

    //*******************************
    //计算函数
    public static int det(int[] b, int r, int c) {
        //TODO *** tem = 1 ***
        int tem = 1;
        int aa = 0;
        int h = 0;
        int k;
        int s = 1;
        //行列数下标数组赋值
        int[] d = new int[c + 1];
        for (int i = 0; i <= c + 1; i++) d[i] = i;
        if (b.length == 1) return b[0];
        if (b.length == 4) return b[0] * b[3] - b[1] * b[2];

        //当行列数的阶大于3时的计算：

        //***全排列的计算***
        if (r > c) {
            h++;
            for (int i = 0; i < c + 1; i++) tem *= b[b[i] + (c + 1) * i];
                if (sa(b, c + 1)) tem *= -1;
            else{
                for (k = r; k <= c; k++) {
                    swap(b[r], b[k]);
                    det(b, r + 1, c);
                    swap(b[r], b[k]);
                }
            }
        }
        return tem += aa;
    }
}
