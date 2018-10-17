package com.cbs;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import com.util.NetJavaShape;

/**
 * Draw类，用于界面的初始化
 * 
 * @author CBS
 */
@SuppressWarnings("serial")
public class Draw extends JFrame {
	private Graphics g;
	private DrawListener dl;

	// 界面初始化方法
	public void showUI() {
		setTitle("画图");//窗体名称
		setSize(1200, 900);//窗体大小
		setDefaultCloseOperation(3);
		setLocationRelativeTo(null);//窗体居中
		FlowLayout layout = new FlowLayout(FlowLayout.LEFT);
		setLayout(layout);//窗体使用流式布局管理器
		this.setResizable(false);//窗体大小不变

		String buttonName[] = { "画直线", "画椭圆", "画曲线", "多边形", "橡皮擦", "拖动线",
				"三角形", "画球形", "笔刷", "喷枪", "色子", "立体矩形", "立体圆", "立体三角",
				"迭代分形", "现代分形", "枫叶", "画树", "mandelbrot集", "L-System", "迭代画线",
				"迭代三角形", "谢尔宾斯基地毯", "画字符", "清空","吸管" ,"矩形","五角星","多线",
				"蝴蝶曲线"};
		
		JPanel jp1=new JPanel(new GridLayout(15, 2,10,10));//用于保存图形按钮，使用网格布局
		dl = new DrawListener();// 实例化DrawListener类的对象
		for (int i = 0; i < buttonName.length; i++) {
			JButton jbutton = new JButton(buttonName[i]);
			jbutton.addActionListener(dl);// 为按钮添加动作监听
			jp1.add(jbutton);
		}
		jp1.setPreferredSize(new Dimension(200, 800));
		this.add(jp1);
		JPanel jp2=new JPanel();//画布面板
		jp2.setPreferredSize(new Dimension(970, 800));
		jp2.setBackground(Color.WHITE);
		this.add(jp2);

		// 定义Color数组，用来存储按钮上要显示的颜色信息
		Color[] colorArray = { Color.BLUE, Color.GREEN, Color.RED, Color.BLACK,
				Color.ORANGE, Color.PINK, Color.CYAN,Color.MAGENTA,Color.DARK_GRAY,
				Color.GRAY,Color.LIGHT_GRAY,Color.YELLOW};
		//用于保存颜色按钮的面板
		JPanel jp3=new JPanel(new GridLayout(1, colorArray.length,3,3));
		// 循环遍历colorArray数组，根据数组中的元素来实例化按钮对象
		for (int i = 0; i < colorArray.length; i++) {
			JButton button = new JButton();
			button.setBackground(colorArray[i]);
			button.setPreferredSize(new Dimension(30, 30));
			//将事件源按钮对象通过addActionListener()监听方法和事件处理类dl对象绑定。
			button.addActionListener(dl);
			jp3.add(button);
		}
		this.add(jp3);
		//添加按钮，作为当前颜色
		JButton nowColor=new JButton();
		nowColor.setPreferredSize(new Dimension(40,40));
		nowColor.setBackground(Color.BLACK);//默认黑色
		add(nowColor);
		dl.setNowColor(nowColor);
		
		setVisible(true);
		g =jp2.getGraphics();// 获取当前的画笔
		dl.setG(g);
		dl.setJ(jp2);
		jp2.addMouseListener(dl);// 为窗体添加鼠标事件监听方法
		jp2.addMouseMotionListener(dl);// 为窗体添加鼠标移动事件监听方法
		
	}

	public void paint(Graphics g) {
		// 一点要先调用父类的构造方法，用来绘制窗体
		super.paint(g);
		for (NetJavaShape shape : dl.getShapes()) {
			shape.draw();
		}
//		for(int i=0;i<dl.getShapes().legnth();i++)
//			dl.getShapes().get(i).draw();

	}

}
