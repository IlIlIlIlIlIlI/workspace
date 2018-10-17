package before0601.exercise_3_SIMCARD;

public class ChinaMbile extends SIM {
    String Number;
    @Override
    public void setNumber(String num) {
        this.Number = num;
    }

    @Override
    public String getNumber() {
        return Number;
    }

    @Override
    public void greet() {
        System.out.println("尊敬的用户，感谢您选择中国移动！");
    }
}
