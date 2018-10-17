package before0601.exercise_3_SIMCARD;

public class Apply {
    public static void main(String[] args) {
        SIM sim_1 = new ChinaMbile();
        SIM sim_2 = new ChinaUnion();

        sim_1.setNumber("18342299347");
        sim_2.setNumber("15768211350");

        /*Phone iphone = new IPhone();
        iphone.insertSIM(sim_1);
        iphone.afterStart();

        iphone.insertSIM(sim_2);
        iphone.afterStart();*/
    }
}
