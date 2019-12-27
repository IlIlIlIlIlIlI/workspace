package exercise_7_Panel.shapes;

public class Circle extends Shape{
    private double radius = 0;
    private static double PI = 3.14;

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double culZC(){
        setZc(2 * PI * getRadius());
        return getZc();
    }
    public double culMJ(){
        setMj(PI * radius * getRadius());
        return getMj();
    }


}
