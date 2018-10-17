package com.dlmu.pyq.exercise_1;

public class HelloWorld {
    public static void main(String[] args) {
        String hello = "Hello";
        String world = " world!";
        //Java设计者为连接字符串，重载了“+”运算符，然鹅也只有“+”运算符被重载，Java中不允许自定义重载运算符
        //具体由编译器转化，使用StringBuilder（单线程，不安全，（StringBuffer,多线程，安全））类中的append方法得到新串
        System.out.println(hello + world);


    }
}
