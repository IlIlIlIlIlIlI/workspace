package exercise_6;

import java.awt.*;

public abstract class Shape {

    private int x1,y1,x2,y2;
    private Color color;
    private String type;
    public Shape(int x1,int y1,int x2,int y2,Color color,String type){
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.color=color;
        this.type=type;
    }
    public abstract void draw(Graphics p);

    public  Color getColor(){
     return color;
    }

    public String getType() {
        return type;
    }

    public int getX_1() {
        return x1;
    }

    public int getX_2() {
        return x2;
    }

    public int getY_1() {
        return y1;
    }

    public int getY_2() {
        return y2;
    }
}