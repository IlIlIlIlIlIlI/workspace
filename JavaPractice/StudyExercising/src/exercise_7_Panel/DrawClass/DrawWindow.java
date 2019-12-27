package exercise_7_Panel.DrawClass;

import javax.swing.*;
import java.awt.*;

public class DrawWindow extends JFrame {
    private JPanel northPanel;
    private Graphics graphics;
    private DrawListener listener;
    private JButton calculButton;

    public DrawWindow(){
        init();
        setVisible(true);
        graphics = this.getGraphics();
        listener.setGraphics(graphics);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setVisible(true);
    }

    public void init(){
        setLayout(new BorderLayout());

        northPanel = new JPanel();
        northPanel.setLayout(new FlowLayout());
        northPanel.setBackground(Color.black);

        //centerPanel = new JPanel();
        //centerPanel.setBackground(Color.white);
        //setBackground(Color.black);
        this.getContentPane().setBackground(Color.white);
        //setPreferredSize(new Dimension(1000,870));

        listener = new DrawListener();

        calculButton = new JButton("数据显示");
        northPanel.add(calculButton);
        calculButton.addActionListener(listener);

        String[] buttonArray = {"铅笔","橡皮擦","直线","矩形","椭圆","圆形","三角形"};
        for (int i = 0;i<buttonArray.length;i++){
            JButton button = new JButton(buttonArray[i]);
            button.addActionListener(listener);
            northPanel.add(button);
        }

        Color[] colorArray = {Color.red,Color.yellow,Color.green,Color.black,Color.blue,Color.gray,Color.cyan,Color.magenta};
        for (int i = 0;i<colorArray.length;i++){
            JButton button = new JButton();
            button.addActionListener(listener);
            button.setBackground(colorArray[i]);
            button.setPreferredSize(new Dimension(30,30));
            northPanel.add(button);
        }

        add(northPanel,BorderLayout.NORTH);
        //add(centerPanel,BorderLayout.CENTER);

        //centerPanel.addMouseListener(listener);
        //centerPanel.addMouseMotionListener(listener);


        addMouseMotionListener(listener);
        addMouseListener(listener);
    }
}
