package exercise_7_Panel.DrawClass;

import exercise_7_Panel.factory.ShapeFactory;
import exercise_7_Panel.shapes.*;
import exercise_7_Panel.shapes.Shape;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class DrawListener extends MouseAdapter implements ActionListener {
    private Graphics graphics;
    private String type = "铅笔";
    private Color color = Color.black;
    //点击：x_1和y_1
    //释放：x_2和y_2
    int x_1,y_1,x_2,y_2;

    String[] calculButton = {"当前矩形: ","当前椭圆: ","当前圆形: ","当前三角形: "};
    JTextField[] textField = new JTextField[calculButton.length];


    public void setGraphics(Graphics graphics) {
        this.graphics = graphics;
        ((Graphics2D)this.graphics).setStroke(new BasicStroke(2));
        //System.out.println(graphics.toString());
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()){
            case "":{
                JButton button = (JButton)e.getSource();
                color = button.getBackground();
                graphics.setColor(color);
                System.out.println("color = " + color);
                break;
            }
            case "数据显示":{
                JFrame calculFrame = new JFrame("数据显示");
                calculFrame.setBounds(50,50,950,900);
                calculFrame.setLayout(new GridLayout(4,2));

                int i = 0;
                for (String str : calculButton) {
                    JButton button = new JButton(str);
                    textField[i] = new JTextField(15);
                    calculFrame.add(button);
                    calculFrame.add(textField[i]);
                    i++;
                }
                calculFrame.setVisible(true);
                break;
            }
            default:{
                this.type = e.getActionCommand();
                System.out.println("type = " + type);
            }
        }
        /*
        if (e.getActionCommand().equals("当前矩形")){
            JFrame recFrame = new JFrame();
            recFrame.setBounds(50,50,500,500);
            recFrame.setLayout(new FlowLayout());
            JTextField inText_1 = new JTextField(5);
            JTextField inText_2 = new JTextField(5);
            JComboBox choice = new JComboBox();
            JButton calculate = new JButton("计算");
            choice.addItem("选择运算符号");
            String[] item = {"+","-","*","/"};
            for (String j : item) {
                choice.addItem(j);
            }
            JTextArea showArea = new JTextArea(9,30);

        }
        */
    }

    @Override
    public void mousePressed(MouseEvent e) {
        x_1 = e.getX();
        y_1 = e.getY();
        //System.out.println(graphics + "\t第一个" +color);
        //graphics.setColor(color);
        //System.out.println(graphics + "\t第二个" +color);
    }

    @Override
    public void mouseReleased(MouseEvent e) {

        Calculator[] calculators = new Calculator[4];

        x_2 = e.getX();
        y_2 = e.getY();
        int minX = Math.min(x_1,x_2);
        int minY = Math.min(y_1,y_2);
        int absX = Math.abs(x_1-x_2);
        int absY = Math.abs(y_1-y_2);
        switch (type) {
            case "直线": {
                graphics.drawLine(x_1,y_1,x_2,y_2);
                break;
            }

            case "矩形": {
                graphics.drawRect(minX, minY, absX, absY);

                Shape rec = ShapeFactory.getShapeInstance(type);

                //calculators[0] = new (absX,absY);
                String str = "矩形的长为：" + absX + "pixel，宽为：" + absY + "pixel，面积为：" + (int)calculators[0].culMJ() + "pixel^2，周长为：" + (int)calculators[0].culZC() + "pixel";
                textField[0].setText(str);

                calculators[0].printToFile(str);
                break;
            }

            case "椭圆": {
                graphics.drawOval(minX, minY, absX, absY);
                int changzhou = absX > absY ? absX : absY;
                int duanzhou = absX < absY ? absX : absY;

                //calculators[1] = new Oval(changzhou,duanzhou);
                String str = "椭圆的长轴为：" + changzhou + "pixel，短轴为：" + duanzhou + "pixel，面积为：" + (int)calculators[1].culMJ() + "pixel^2";
                textField[1].setText(str);

                calculators[1].printToFile(str);
                break;
            }

            case "圆形": {
                graphics.drawOval(minX, minY, absX, absX);
                double dR = Math.sqrt((double) (absX*absX + absY*absY));

                //calculators[2] = new Circle(dR/2);
                String str = "圆形的圆心为：(" + absX + "," + absY + ")，半径为：" + (int)(dR/2) + "pixel，面积为" + (int)calculators[2].culMJ() + "pixel^2，周长为：" + (int)calculators[1].culZC() + "pixel";
                textField[2].setText(str);

                calculators[2].printToFile(str);
                break;
            }

            case "三角形": {
                graphics.drawLine(x_1,y_1,x_2,y_2);
                graphics.drawLine(x_1,y_1,x_1,y_2);
                graphics.drawLine(x_1,y_2,x_2,y_2);

                double a = Math.sqrt((double) (absX*absX + absY*absY));
                double b = Math.sqrt((double) (Math.abs(x_1-x_2)*Math.abs(x_1-x_2) + absY*absY));
                double c = Math.sqrt((double) (Math.abs(x_1-x_2)*Math.abs(x_1-x_2) + absY*absY));

                //calculators[3] = new Triangle(a,b,c);
                String str = "三角形的三边长为：" + (int)a + "pixel  " + (int)b + "pixel  " + (int)c + "pixel，面积为：" + (int)calculators[3].culMJ() + "pixel^2，周长为：" + (int)calculators[1].culZC() + "pixel";
                textField[3].setText(str);

                calculators[3].printToFile(str);
                break;
            }
        }
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        x_2 = e.getX();
        y_2 = e.getY();
        switch (type){
            case "铅笔":
            {
                ((Graphics2D)this.graphics).setStroke(new BasicStroke(2));
                graphics.setColor(color);
                graphics.drawLine(x_1,y_1,x_2,y_2);
                x_1 = x_2;
                y_1 = y_2;
                break;
            }
            case "橡皮擦":
            {
                ((Graphics2D)graphics).setStroke(new BasicStroke(50));
                graphics.setColor(Color.white);
                graphics.drawLine(x_1,y_1,x_2,y_2);
                x_1 = x_2;
                y_1 = y_2;
                break;
            }
            default:{
                ((Graphics2D)this.graphics).setStroke(new BasicStroke(2));
                graphics.setColor(color);
            }
        }
    }
}
