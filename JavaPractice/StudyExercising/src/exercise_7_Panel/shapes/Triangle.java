package exercise_7_Panel.shapes;

public class Triangle extends Shape {
    private double a = 0;
    private double b = 0;
    private double c = 0;

    public double culZC(){
        this.setZc(a + b + c);
        return getZc();
    }

    public double culMJ(){
        double p =(a + b + c) / 2;
        double tem2 =p * (p-a)* (p-b)* (p-c);
        setMj(Math.sqrt(tem2));
        return getMj();
    }
}
