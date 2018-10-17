package test;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int classNum;
        int stuNum;
        double sum = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("***请输入班级数：***");
        classNum = input.nextInt();
        System.out.println("***请输入学生数：***");
        stuNum = input.nextInt();
        for (int i = 1; i <= classNum; i++) {
            for (int j = 1; j <= stuNum; j++) {
                System.out.println("***" + j + "." + "请输入" + i + "班的学生成绩：***");
                double score = input.nextDouble();
                sum += score;
            }
            System.out.println("***" + i + "班学生成绩平均分为：***" + sum / stuNum);
        }
    }
}
