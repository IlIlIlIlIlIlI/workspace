package exercise_7.shapes;

public class Oval extends Shape {
    private double changzhou;
    private double duanzhou;
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
    public Oval(double changzhou,double duanzhou){
        this.setChangzhou(changzhou);
        this.setDuanzhou(duanzhou);
        this.setName("椭圆");
    }
    @Override
    public double culMJ() {
        setMj(PI*(getChangzhou()*getDuanzhou())/4);
        return getMj();
    }

    @Override
    public double culZC() {
        return 0;
    }
}
