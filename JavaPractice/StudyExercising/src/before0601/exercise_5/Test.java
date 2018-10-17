package before0601.exercise_5;

public class Test {
    public static void main(String[] args) {
    SingleClass aSingle = SingleClass.getSingle();
    SingleClass bSingle = SingleClass.getSingle();
        System.out.println("YesOrNot\n" + (aSingle == bSingle));
        aSingle.gene = 9;
        bSingle.gene = 7;
        System.out.println(aSingle);
        System.out.println(aSingle.hashCode());
        System.out.println("//////////////////////////////////////////////////////");

        Bank bank = new Bank();
        try {
            bank.income(8465,-498);
            bank.income(456,-159);
            bank.income(685,-9689);
            bank.income(12,-999999);
            System.out.printf("银行目前还有 %d 元\n",bank.getMoney());
        }
        catch (BankException e) {
            System.out.println("计算收益时出现如下问题：");
            System.out.println(e.getWarnMessage());
        }
        System.out.printf("银行目前还有 %d 元\n",bank.getMoney());

        int i = 5 / 0;
        System.out.println(i);
    }
}
