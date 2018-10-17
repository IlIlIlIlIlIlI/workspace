package before0601.exercise_1;

public class PrintPrimeIn10E10 {
    public static void PP(){
        int maxn = 100000000;
        boolean[] check = new boolean[maxn];
        int[] pri = new int[maxn];
        int tot = 0;
        for (int i = 0;i<check.length;i++) check[i] = true;
        for (int i = 0;i<pri.length;i++) pri[i] = i;
        for (int i = 2; i < maxn; ++i){
                if (!check[i]) pri[tot++] = i;
                for (int j = 0; j < tot && pri[j] * i < maxn; ++j){
                    check[pri[j]*i] = true;
                    if ((i % pri[j]) == 0) break;
                }
            }
            for(int i = 0;i<pri.length;i++){
                System.out.print(pri[i] + " ");
                if (i % 50 == 0) System.out.println();
            }
    }

    public static void main(String[] args) {
        PP();
    }
}
