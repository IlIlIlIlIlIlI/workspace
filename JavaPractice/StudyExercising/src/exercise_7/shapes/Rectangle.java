package exercise_7.shapes;

public class Rectangle extends Shape {
    private double len;
    private double wid;

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

    public Rectangle(double len, double wid){
        this.setLen(len);
        this.setWid(wid);
        this.setName("矩形");
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
