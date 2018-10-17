package before0601.exercise_1;

import java.math.BigInteger;

public class Test_1 {
    public static void main(String[] args) {
        BigInteger a = new BigInteger("0");
        BigInteger i = new BigInteger("100000000000");
        BigInteger e = new BigInteger("1");
        String he = null;
        for (;i.equals(0) ; i.subtract(e)){
            he = a.add(i).toString();
        }

        System.out.println(he);
    }
}
