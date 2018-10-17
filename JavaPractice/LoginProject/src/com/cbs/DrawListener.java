package com.cbs;

import java.awt.AWTException;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;

import com.shape.Imp3DOval;
import com.shape.Imp3DRact;
import com.shape.Imp3DTract;
import com.shape.ImpBrush;
import com.shape.ImpClean;
import com.shape.ImpColorzi;
import com.shape.ImpCur;
import com.shape.ImpEraser;
import com.shape.ImpFillOval;
import com.shape.ImpFillRact;
import com.shape.ImpFiveXing;
import com.shape.ImpInteF;
import com.shape.ImpInteLine;
import com.shape.ImpInteTract;
import com.shape.ImpLSystem;
import com.shape.ImpLeaf;
import com.shape.ImpLine;
import com.shape.ImpMandelrot;
import com.shape.ImpManyLine;
import com.shape.ImpMoveLine;
import com.shape.ImpNowF;
import com.shape.ImpOval;
import com.shape.ImpPgun;
import com.shape.ImpPolygon;
import com.shape.ImpTract;
import com.shape.ImpTree;
import com.shape.ImpXBDT;
import com.util.NetJavaShape;

/**
 * 事件处理类
 * 
 * @author CBS
 * 
 */

public class DrawListener implements MouseListener, MouseMotionListener, ActionListener {
	// 定义图形的集合
	private List<NetJavaShape> shapes = new ArrayList<NetJavaShape>();
//	 private MyList<NetJavaShape> shapes=new MyList<NetJavaShape>(0, 1);
	NetJavaShape shape;
	private int x1, y1, x2, y2, x, y;// 记录两次鼠标的点击坐标
	private Graphics g;// 从界面获取画布对象
	private String str;// 记录当前按钮的信息，区分不同的按钮
	private Color color = Color.BLACK;// 记录画笔的颜色信息
	private int f = 1;// 控制变量，用于更新坐标
	private JButton nowColor;// 声明当前颜色
	private JPanel j;// 获取窗体

	// public MyList<NetJavaShape> getShapes() {
	// return shapes;
	// }

	public void setJ(JPanel j) {
		this.j = j;
	}

	public void setNowColor(JButton nowColor) {
		this.nowColor = nowColor;
	}

	public List<NetJavaShape> getShapes() {
		return shapes;
	}

	public void setShapes(List<NetJavaShape> shapes) {
		this.shapes = shapes;
	}

	public DrawListener() {
	}

	public void setG(Graphics g) {
		this.g = g;
	}

	// 鼠标按下时的处理方法
	public void mousePressed(MouseEvent e) {

		// 记录第一次点击的位置；由对象e得到
		if (f == 1) {
			x1 = e.getX();
			y1 = e.getY();
		}
		// 吸管方法
		if ("吸管".equals(str)) {
			int x= e.getX();
			int y= e.getY();
			try {
				Robot robot = new Robot();
				//用j.getLocation()回出现坐标偏移
				BufferedImage i = robot.createScreenCapture(new Rectangle(
						j.getLocationOnScreen(), j.getSize()));
				color = new Color(i.getRGB(x, y));
//				color=robot.getPixelColor(x, y);
				nowColor.setBackground(color);
			} catch (AWTException e1) {
				e1.printStackTrace();
			}

		}

	}

	// 鼠标点击时的处理方法
	public void mouseClicked(MouseEvent e) {

		// 画字符
		if ("蝴蝶曲线".equals(str)) {
			DrawBuf();
		}

		// 清空画板
		if ("清空".equals(str)) {
			g.setColor(Color.WHITE);
			shape = new ImpClean(g);
			shape.draw();
			shapes.add(shape);
		}

		// 画地毯
		if ("谢尔宾斯基地毯".equals(str)) {
			shape = new ImpXBDT(x1, y1, 300, 5, g, color);
			shape.draw();
			shapes.add(shape);
		}

		if ("三角形".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpTract(g, x1, y1, x2, y2, x, y, color);
			shape.draw();
			shapes.add(shape);
			f = 1;

		}
		// 迭代三角形
		if ("迭代三角形".equals(str)) {
			shape = new ImpInteTract(600, 100, 220, 700, 900, 700, 10, g, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("立体三角".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new Imp3DTract(g, x1, y1, x2, y2, x, y, color);
			shape.draw();
			shapes.add(shape);
			for (int i = 0; i < 4; i++) {
				shape = new Imp3DTract(g, x1 += 10, y1 += 10, x2 -= 10,
						y2 += 10, x, y -= 5, color);
				shape.draw();
				shapes.add(shape);
			}
			f = 1;
		}
		if ("多边形".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpPolygon(g, x, y, x2, y2, x1, y1, color);
			shape.draw();
			shapes.add(shape);
			x2 = x;
			y2 = y;
			if (x > x1 - 2 && x < x1 + 2 && y > y1 - 2 && y1 < y1 + 2) {
				f = 1;
			}
		}

		// 色子的实现方法
		if ("色子".equals(str)) {
			shape = new ImpColorzi(g, color);
			shape.draw();
			shapes.add(shape);
		}

		if ("迭代分形".equals(str)) {
			shape = new ImpInteF(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// 迭代分形二
		if ("现代分形".equals(str)) {
			shape = new ImpNowF(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// 画枫叶
		if ("枫叶".equals(str)) {
			shape = new ImpLeaf(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// 画曼什么集
		if ("mandelbrot集".equals(str)) {
			shape = new ImpMandelrot(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// 画树
		if ("画树".equals(str)) {
			shape = new ImpTree(g, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("L-System".equals(str)) {
			shape = new ImpLSystem(g, color);
			shape.draw();
			shapes.add(shape);
		}

	}

	// 鼠标释放时的处理方法
	public void mouseReleased(MouseEvent e) {

		// 记录鼠标释放时的坐标
		if (f == 1) {
			x2 = e.getX();
			y2 = e.getY();
		}
		// 迭代画线
		if ("迭代画线".equals(str)) {
			shape = new ImpInteLine(x1, y1, x2, y1, g, color);
			shape.draw();
			shapes.add(shape);
		}

		// 画矩形
		if ("矩形".equals(str)) {
			shape = new ImpFillRact(g, x1, y1, x2, y2, color);
			shape.draw();
			shapes.add(shape);
		}
		// 画五角星
		if ("五角星".equals(str)) {
			shape = new ImpFiveXing(x1, y1, x2, y2, g, color);
			shape.draw();
			shapes.add(shape);
		}

		// 两个坐标的得到了，可以用于直线的绘制，调用画布对象g方法，在界面上面画出直线
		if ("画直线".equals(str)) {
			shape = new ImpLine(g, x1, y1, x2, y2, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("画椭圆".equals(str)) {
			shape = new ImpOval(g, x1, y1, x2, y2, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("三角形".equals(str) && f == 1) {
			g.setColor(color);
			g.drawLine(x1, y1, x2, y2);
			f++;
		}
		if ("立体三角".equals(str) && f == 1) {
			g.setColor(color);
			g.drawLine(x1, y1, x2, y2);
			shape.draw();
			shapes.add(shape);
			f++;
		}
		if ("多边形".equals(str) && f == 1) {
			shape = new ImpPolygon(g, x1, y1, x2, y2, x1, y1, color);
			shape.draw();
			shapes.add(shape);
			f++;
		}
		int r = Math.abs(x1 - x2);
		if ("画球形".equals(str)) {
			for (int i = r; i > 0; i--) {
				shape = new ImpFillOval(g, x1 += 1, y1 += 1, x2 -= 1, y2 -= 1,
						color);
				shape.draw();
				shapes.add(shape);
			}
		}

		if ("立体矩形".equals(str)) {
			for (int i = 0; i < 4; i++) {
				shape = new Imp3DRact(g, x1 += 4, y1 += 4, x2 -= 4, y2 -= 4,
						color);
				shape.draw();
				shapes.add(shape);
			}
		}
		if ("立体圆".equals(str)) {
			for (int i = 0; i < 4; i++) {
				shape = new Imp3DOval(g, x1 += 10, y1 += 10, x2 -= 10,
						y2 -= 10, color);
				shape.draw();
				shapes.add(shape);
			}
		}

		if ("多线".equals(str)) {
			for (int i = 0; i < 5; i++) {
				shape = new ImpManyLine(g, x1 += 22, y1 -= 10, x2 -= 15,
						y2 -= 10, color);
				shape.draw();
				shapes.add(shape);
			}
		}

	}

	// 鼠标进入时的处理方法
	public void mouseEntered(MouseEvent e) {

	}

	// 鼠标退出时的处理方法
	public void mouseExited(MouseEvent e) {

	}

	public void actionPerformed(ActionEvent e) {
		if ("".equals(e.getActionCommand())) {
			JButton jb = (JButton) e.getSource();
			color = jb.getBackground();
			nowColor.setBackground(color);
		} else {
			str = e.getActionCommand();
		}
	}

	// 鼠标拖动时的处理方法
	public void mouseDragged(MouseEvent e) {
		if ("画曲线".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpCur(g, x1, y1, x, y, color);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}
		if ("拖动线".equals(str)) {
			color = Color.WHITE;
			shape = new ImpMoveLine(g, x1, y1, x, y, color);
			shape.draw();
			shapes.add(shape);
			x = e.getX();
			y = e.getY();
			color = nowColor.getBackground();
			shape = new ImpMoveLine(g, x1, y1, x, y, color);
			shape.draw();
			shapes.add(shape);

		}
		if ("橡皮擦".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpEraser(g, x1, y1, x, y);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}
		if ("笔刷".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpBrush(g, x1, y1, x, y, color);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}
		if ("喷枪".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpPgun(g, x1, y1, color);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}

	}

	// 鼠标释放时的移动方法
	public void mouseMoved(MouseEvent e) {

	}

	// 迭代画线的算法
	public void drawInteLine(int x1, int y1, int x2, int y2, Graphics g) {
		if ((x2 - x1) > 4) {
			drawInteLine(x1, y1 + 20, x1 + (x2 - x1) / 3, y2 + 20, g);
			drawInteLine(x2 - (x2 - x1) / 3, y1 + 20, x2, y2 + 20, g);
		}
		g.drawLine(x1, y1, x2, y2);
	}

	// 迭代画三角形
	public void drawInteTract(int x1, int y1, int x2, int y2, int x3, int y3,
			Graphics g, int i) {
		if (i > 0) {
			drawInteTract(x1, y1, (x1 + x3) / 2, (y1 + y3) / 2, (x2 + x1) / 2,
					(y2 + y1) / 2, g, i - 1);
			drawInteTract((x1 + x2) / 2, (y1 + y2) / 2, x2, y2, (x2 + x3) / 2,
					(y2 + y3) / 2, g, i - 1);
			drawInteTract((x3 + x2) / 2, (y3 + y2) / 2, (x1 + x3) / 2,
					(y1 + y3) / 2, x3, y3, g, i - 1);
		}
		g.drawLine(x1, y1, x2, y2);
		g.drawLine(x1, y1, x3, y3);
		g.drawLine(x3, y3, x2, y2);
	}

	// 迭代画谢尔宾斯基地毯
	public void drawXBRact(int x, int y, int d, Graphics g, int n) {
		if (n > 0) {
			n--;
			int x1, y1, Ind;
			int x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
			Ind = d / 3;
			x1 = x + Ind;
			y1 = y + Ind;
			g.fillRect(x1, y1, Ind, Ind);
			x2 = x + Ind;
			y2 = y;
			x3 = x + 2 * Ind;
			y3 = y;
			x4 = x;
			y4 = y + Ind;
			x5 = x;
			y5 = y + Ind * 2;
			x6 = x + Ind;
			y6 = y + Ind * 2;
			x7 = x + Ind * 2;
			y7 = y + Ind * 2;
			x8 = x + Ind * 2;
			y8 = y + Ind;
			drawXBRact(x, y, Ind, g, n);
			drawXBRact(x2, y2, Ind, g, n);
			drawXBRact(x3, y3, Ind, g, n);
			drawXBRact(x4, y4, Ind, g, n);
			drawXBRact(x5, y5, Ind, g, n);
			drawXBRact(x6, y6, Ind, g, n);
			drawXBRact(x7, y7, Ind, g, n);
			drawXBRact(x8, y8, Ind, g, n);
		}
	}
	/**
	 * 蝴蝶曲线
	 * @param t参数，0<=t<12pi
	 */
	public void DrawBuf(){
		double x,y;
		g.setColor(Color.GREEN);
		for(double i=0;i<=1000;i++){
			x=Math.sin(i)*(Math.pow(Math.E, Math.cos(i)-2*Math.cos(i*4)-Math.pow(Math.sin(i/12.0), 5)));
			y=Math.cos(i)*(Math.pow(Math.E, Math.cos(i)-2*Math.cos(i*4)-Math.pow(Math.sin(i/12.0), 5)));
			g.drawLine((int)x*100+400, (int)y*100+400, (int)x*100+400, (int)y*100+400);
		}
		
	}
}
