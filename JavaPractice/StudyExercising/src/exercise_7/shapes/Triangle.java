package exercise_7.shapes;

public class Triangle extends Shape {
    private double a;
    private double b;
    private double c;

    public Triangle(double a,double b,double c){
        this.a = a;
        this.b = b;
        this.c = c;
        this.setName("三角形");
    }
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
