package exercise_7_Panel.shapes;

public class Oval extends Shape {
    private double changzhou = 0;
    private double duanzhou = 0;
    private static double PI = 3.14;

    public void setChangzhou(double changzhou) {
        this.changzhou = changzhou;
    }

    public void setDuanzhou(double duanzhou) {
        this.duanzhou = duanzhou;
    }

    public double getChangzhou() {
        return changzhou;
    }

    public double getDuanzhou() {
        return duanzhou;
    }

    public double culMJ() {
        setMj(PI*(getChangzhou()*getDuanzhou())/4);
        return getMj();
    }

    public double culZC() {
        return 0;
    }
}
