package exercise_7.shapes;

public class Circle extends Shape{
    private double radius;
    private static double PI = 3.14;

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Circle(double radius){
        this.setRadius(radius);
        this.setName("圆形");
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
