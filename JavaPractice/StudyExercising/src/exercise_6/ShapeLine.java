package exercise_6;

import java.awt.*;

public class ShapeLine extends Shape {


    public ShapeLine(int x1,int y1,int x2,int y2,Color color,String type){
        super(x1,y1,x2,y2,color,type);
    }

    @Override
    public void draw(Graphics graphics){
        Graphics2D graphics2D = (Graphics2D)graphics;
        graphics2D.setStroke(new BasicStroke(1));
        graphics.setColor(this.getColor());
        switch(getType()){
            case "直线":
                graphics.drawLine(getX_1(), getY_1(), getX_2(),getY_2());
                break;
            case "矩形":
                graphics.drawRect(getX_1(), getY_1(), Math.abs(getX_1()-getX_2()) , Math.abs(getY_1()-getY_2()));
                break;
            case "椭圆":
                graphics.drawOval(getX_1(), getY_1(), Math.abs(getX_1()-getX_2()) , Math.abs(getY_1()-getY_2()));
                break;
            case "圆形":
            {
                graphics.drawOval(getX_1(), getY_1(), Math.abs(getX_1()-getX_2()) , Math.abs(getX_1()-getX_2()));
                break;
            }
            case "铅笔":
            {
                graphics.drawLine(getX_1(), getY_1(), getX_2(), getY_2());
                break;

            }
            case "橡皮擦":
            {
                graphics2D.setStroke(new BasicStroke(40));
                graphics.drawLine(getX_1(), getY_1(), getX_2(), getY_2());
                break;
            }
        }
    }
}