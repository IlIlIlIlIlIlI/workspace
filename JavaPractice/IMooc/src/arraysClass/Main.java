package arraysClass;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println("*****************************");
        int[][] b = new int[][]{{4, 8, 6}, {65, 96, 6}, {64, 654, 6}};
        int[] c = new int[9];
        int count = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                c[count++] = b[i][j];
        try {
            for (int i = 0; i < c.length; i++)
                System.out.println(c[i]);
        } catch (Exception e) {
            e.printStackTrace();
        }


    }
}
