package before0601.exercise_5;

public class SingleClass {
    public int gene = 0;
    private static SingleClass single = new SingleClass();
    private SingleClass(){
    }

    public static SingleClass getSingle() {
        return single;
    }
}
