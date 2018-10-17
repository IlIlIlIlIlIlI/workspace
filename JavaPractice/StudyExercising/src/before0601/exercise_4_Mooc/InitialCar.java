package before0601.exercise_4_Mooc;

import java.util.Scanner;

public class InitialCar {
    public static void main(String[] args) {
        System.out.println("您是否想要租车？是：1      否：2");

        Scanner in = new Scanner(System.in);
        int inputNum = in.nextInt();

        if (inputNum == 1){
            System.out.println("以下是可租车的类型和价格表");
            System.out.println("汽车名称" + '\t' + "载客数" + '\t' + "租金/天" + '\t' + "载货量");

            //int[] a = {1,2,3,4};
            //int[] a = new int[]{1,2,3,4};两者相同，定义时直接初始化数组
            //JAVA 里面的数组名是一个引用变量，引用变量是放在是放在一个栈里面，而JAVA数组本身就是对象，
            //Java中对象是在堆中的，因此数组无论保存原始类型还是其他对象类型，数组对象本身是在堆中的。
            //所以如果不new一下，就无法得到这个数组，即引用变量没有引用的对象。
            //而在C++中，数组名实际上是数组的首地址，是一个指针，数组在声明之后就已经生成了这个数组对象。


            Car[] carArry = {};

            //int[] a = {};
            //int[] b = new int[]{};
        }
    }
}
