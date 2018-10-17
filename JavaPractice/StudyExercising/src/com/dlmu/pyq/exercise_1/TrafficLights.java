package com.dlmu.pyq.exercise_1;

import java.util.Scanner;

public class TrafficLights {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String Light = input.nextLine();
        if (Light.equals("红")){
            System.out.println("stop");
        }else if (Light.equals("黄")){
            System.out.println("wait");
        }else if (Light.equals("绿")){
            System.out.println("go");
        }else {
            System.out.println("call police");
        }
    }
}
