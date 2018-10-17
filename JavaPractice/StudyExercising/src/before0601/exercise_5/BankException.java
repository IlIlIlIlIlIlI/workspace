package before0601.exercise_5;

public class BankException extends Exception {
    String warnMessage;
    public BankException(){
        warnMessage = "银行的钱不够你花啦~";
    }
    public BankException(int in,int out){
        warnMessage = "入账资金 " + in + " 是负数或支出 " + out + " 是正数，不符合系统要求。";
    }

    public String getWarnMessage() {
        return warnMessage;
    }
}
