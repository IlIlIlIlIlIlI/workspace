package before0601.exercise_3_SIMCARD;

public class ChinaUnion extends SIM {
    String Number;
    @Override
    public void setNumber(String num) {
        Number = num;
    }

    @Override
    public String getNumber() {
        return Number;
    }

    @Override
    public void greet() {
        System.out.println("尊敬的用户，感谢您选择中国联通！");
    }
}
