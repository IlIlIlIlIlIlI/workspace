package com.dlmu.pyq.exercise_1;

public class IntFlowDouble {
    public static void main(String[] args) {
        byte aByte = 127;
        System.out.println("定义了byte类型变量aByte，值等于=" + aByte);

        short aShort = 32767;
        System.out.println("定义了short类型变量aShort，值等于=" + aShort);

        int aInt = 2147483647;
        System.out.println("定义了int类型变量aInt，值等于=" + aInt);

        long aLong = 9223372036854775807L;
        System.out.println("定义了long类型变量aLong，值等于=" + aLong);

        float aFloat = 3.40282347000000000000000000000000000000000000000000000000000000000E38F;
        System.out.println("定义了float类型变量aFloat，值等于=" + aFloat);//6~7位

        double aDouble = 1.11111111111111111111111111111111111111111111111111111111111111111E308;
        System.out.println("定义了double类型变量aDouble，值等于=" + aDouble);//15位

        char aChar = '\u2122';
        System.out.println("定义了char类型变量aChar，值等于=" + aChar);

        boolean aBoolean = false;
        System.out.println("定义了boolean类型变量aBoolean，值等于=" + aBoolean);

        int i = 1;
        char[] myName = {'皮','永','琪'};
        for (int aName : myName){
            System.out.println((i++) + ". 十进制的Unicode：" + aName);
            System.out.println((i++) + ". 十六进制的Unicode：" + Integer.toHexString(aName));
        }
    }
}
