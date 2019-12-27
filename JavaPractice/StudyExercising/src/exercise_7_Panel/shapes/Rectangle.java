package exercise_7_Panel.shapes;

public class Rectangle extends Shape {
    private double len = 0;
    private double wid = 0;

    public void setLen(double len) {
        this.len = len;
    }

    public void setWid(double wid) {
        this.wid = wid;
    }

    public double getLen() {
        return len;
    }

    public double getWid() {
        return wid;
    }

    public double culZC(){
        this.setZc(2 * (len + wid));
        return getZc();
    }

    public double culMJ(){
        setMj(len * wid);
        return getMj();
    }
}
