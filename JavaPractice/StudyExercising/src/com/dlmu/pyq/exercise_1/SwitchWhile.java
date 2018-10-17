package com.dlmu.pyq.exercise_1;

import java.util.Scanner;

public class SwitchWhile {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int month = input.nextInt();
        switch (month) {
            case 2:
                System.out.println(28);
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                System.out.println(30);
                break;
            default:
                System.out.println(31);
        }

        //////////////////////////////////////////

        int i = 1;
        int jiAns = 0;
        int oAns = 0;
        while (i <= 100) {
            if (i % 2 == 0) {
                oAns += i;
            } else if (i % 2 != 0) {
                jiAns += i;
            }

            if ((i % 5 == 0) && (i % 6 == 0)) {
                System.out.println("能同时被5和6整除：" + i);
            }
            i++;
        }
        System.out.println("奇数和：" + jiAns + "\n偶数和：" + oAns);

        ////////////////////////////////////////////////////////////

        int n = input.nextInt();
        long result = 1;
        for (int j = 1; j < n; j++) {
            result *= n;
        }
        System.out.println(result);
    }
}