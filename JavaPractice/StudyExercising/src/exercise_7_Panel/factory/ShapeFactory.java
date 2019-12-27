package exercise_7_Panel.factory;

import exercise_7_Panel.shapes.*;

import java.text.DateFormat;

public class ShapeFactory {
    private static Shape shape = null;

    public static Shape getShapeInstance(String str){
        switch (str){
            case "圆形":{
                shape = new Circle();
                break;
            }
            case "椭圆":{
                shape = new Oval();
                break;
            }
            case "矩形":{
                shape = new Rectangle();
                break;
            }
            case "三角形":{
                shape = new Triangle();
                break;
            }
        }
        return shape;
    }
}
