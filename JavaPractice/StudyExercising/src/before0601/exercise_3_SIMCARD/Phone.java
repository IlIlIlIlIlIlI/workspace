package before0601.exercise_3_SIMCARD;

public abstract class Phone {
    SIM[] simCard = new SIM[2];
    public abstract void insertSIM(SIM simCard);
    public abstract void afterStart();
}
