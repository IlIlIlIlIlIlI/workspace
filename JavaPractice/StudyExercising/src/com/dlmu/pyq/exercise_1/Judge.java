package com.dlmu.pyq.exercise_1;

import java.util.Scanner;

public class Judge {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int score = input.nextInt();
        if (score >= 60){
            if (score < 80){
                System.out.println("同学，你的成绩为中等！");
            }else if (score < 90){
                System.out.println("同学，你的成绩为优良！");
            }else if (score <= 100){
                System.out.println("同学，你的成绩为优秀！");
            }else{
                System.out.println("同学，你怕是开挂了！");
            }
        }else{
            System.out.println("同学，你的成绩为不及格！");
        }

        /////////////////////////////////////////////////
        long ans = 1;
        for (int i = 1;i<=10;i++){
            ans *= i;
        }
        System.out.println(ans);


        int[] java = {1541,2845,3845,4845,5845,2845,3451,1841,4129};
        for (int i : java) {
            System.out.println((char)i);
        }
    }
}
