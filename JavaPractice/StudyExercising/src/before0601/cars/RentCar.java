package before0601.cars;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RentCar {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        System.out.println("欢迎使用哒哒租车系统！"+"\n"+"您是否要租车：1是，0否");
        //控制台接收输入
        Scanner sc = new Scanner(System.in);
        //用户输入选择
        int input = sc.nextInt();

        //创建对象数组并初始化
        Car[] car = {new PassengerCar("奥迪",500,4),new PassengerCar("马自达",400,4),new Pickup("皮卡",450,4,2),new Van("松花江",400,4),new Van("依维柯",1000,20)};
        //创建List对象，用于存储用户选择车辆序号信息
        List<Integer> list = new ArrayList<Integer>();
        int i = 1;
        if(input == 1) {
            System.out.println("您可以租车的类型及价目表：");
            System.out.println("序号\t汽车名称\t租金\t  容量");
            //循环输出各类型车辆数据
            for(Car rentCar:car) {
                //判断对象是否是类的实例
                if(rentCar instanceof PassengerCar){
                    System.out.println((i++)+"\t"+rentCar.getName()+"\t"+rentCar.getPrice()+"元/天\t"+((PassengerCar)rentCar).getPeople()+"人");
                }
                if(rentCar instanceof Van) {
                    System.out.println((i++)+"\t"+rentCar.getName()+"\t"+rentCar.getPrice()+"元/天\t"+((Van)rentCar).getWeight()+"吨");
                }
                if(rentCar instanceof Pickup) {
                    System.out.println((i++)+"\t"+rentCar.getName()+"\t"+rentCar.getPrice()+"元/天\t"+((Pickup)rentCar).getPeople()+"人,"+((Pickup)rentCar).getWeight()+"吨");
                }
            }
            System.out.println("请输入您要租车的数量：");
            //输入用户租车数量
            int number = sc.nextInt();
            //将选择的车辆序号出入list对象中
            for(int j=0;j<number;j++) {
                System.out.println("请输入第"+(j+1)+"辆车的序号：");
                int serial = sc.nextInt();
                list.add(serial);
            }
            System.out.println("请输入第租车天数：");
            //用户输入租车天数
            int day = sc.nextInt();
            System.out.println("您的账单");
            System.out.print("可载人的车有：");
            //总人数
            int peopleSum = 0;
            //总重量
            int weightSum = 0;
            //总价格
            int priceSum = 0;
            //遍历list，并输入载人车辆信息
            for(int j=0;j<list.size();j++) {
                //判断接收的序号对应的类是否与输出类型一致
                if(car[(Integer)list.get(j)-1].getClass()==PassengerCar.class) {
                    System.out.print(car[(Integer)list.get(j)-1].getName()+"\t");
                    //统计总人数
                    peopleSum += ((PassengerCar)car[(Integer)list.get(j)-1]).getPeople();
                    //统计总价格
                    priceSum+=((PassengerCar)car[(Integer)list.get(j)-1]).getPrice();

                }else if(car[(Integer)list.get(j)-1].getClass()==Pickup.class){
                    System.out.print(car[(Integer)list.get(j)-1].getName()+"\t");
                    peopleSum += ((Pickup)car[(Integer)list.get(j)-1]).getPeople();
                    priceSum+=((Pickup)car[(Integer)list.get(j)-1]).getPrice();
                }
            }
            //输出总人数
            System.out.println("共载人："+peopleSum+"人");
            System.out.print("可载货的车有：");
            //遍历list，并输出载货车辆信息
            for(int j=0;j<list.size();j++) {
                //判断接收的序号对应的类是否与输出类型一致
                if(car[(Integer)list.get(j)-1].getClass()==Van.class) {
                    System.out.print(car[(Integer)list.get(j)-1].getName()+"\t");
                    weightSum += ((Van)car[(Integer)list.get(j)-1]).getWeight();
                    priceSum+=((Van)car[(Integer)list.get(j)-1]).getPrice();
                }else if(car[(Integer)list.get(j)-1].getClass()==Pickup.class){
                    System.out.print(car[(Integer)list.get(j)-1].getName()+"\t");
                    //统计总重量
                    weightSum += ((Pickup)car[(Integer)list.get(j)-1]).getWeight();
                }
            }
            //输出总重量
            System.out.println("共载货："+weightSum+"吨");
            //输出总价格
            System.out.print("租车总价格："+priceSum*day+"元");
        }else if(input == 0){
            System.out.println("谢谢使用哒哒租车系统！");
        }else {
            System.out.println("输入错误，请输入1或0！");
        }
    }
}
