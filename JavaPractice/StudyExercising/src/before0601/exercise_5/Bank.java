package before0601.exercise_5;

public class Bank {
    private int money;
    public void income(int in,int out) throws BankException {
        if (in <0 || out >0){
            throw new BankException(in,out);
        }
        int pureIncome = in + out;
        System.out.println("本次纯收入为：" + pureIncome);
        money += pureIncome;
        if (getMoney()<0){
            throw new BankException();
        }
    }

    public int getMoney() {
        return money;
    }
}
