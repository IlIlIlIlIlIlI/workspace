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
 * �¼�������
 * 
 * @author CBS
 * 
 */

public class DrawListener implements MouseListener, MouseMotionListener, ActionListener {
	// ����ͼ�εļ���
	private List<NetJavaShape> shapes = new ArrayList<NetJavaShape>();
//	 private MyList<NetJavaShape> shapes=new MyList<NetJavaShape>(0, 1);
	NetJavaShape shape;
	private int x1, y1, x2, y2, x, y;// ��¼�������ĵ������
	private Graphics g;// �ӽ����ȡ��������
	private String str;// ��¼��ǰ��ť����Ϣ�����ֲ�ͬ�İ�ť
	private Color color = Color.BLACK;// ��¼���ʵ���ɫ��Ϣ
	private int f = 1;// ���Ʊ��������ڸ�������
	private JButton nowColor;// ������ǰ��ɫ
	private JPanel j;// ��ȡ����

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

	// ��갴��ʱ�Ĵ�����
	public void mousePressed(MouseEvent e) {

		// ��¼��һ�ε����λ�ã��ɶ���e�õ�
		if (f == 1) {
			x1 = e.getX();
			y1 = e.getY();
		}
		// ���ܷ���
		if ("����".equals(str)) {
			int x= e.getX();
			int y= e.getY();
			try {
				Robot robot = new Robot();
				//��j.getLocation()�س�������ƫ��
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

	// �����ʱ�Ĵ�����
	public void mouseClicked(MouseEvent e) {

		// ���ַ�
		if ("��������".equals(str)) {
			DrawBuf();
		}

		// ��ջ���
		if ("���".equals(str)) {
			g.setColor(Color.WHITE);
			shape = new ImpClean(g);
			shape.draw();
			shapes.add(shape);
		}

		// ����̺
		if ("л����˹����̺".equals(str)) {
			shape = new ImpXBDT(x1, y1, 300, 5, g, color);
			shape.draw();
			shapes.add(shape);
		}

		if ("������".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpTract(g, x1, y1, x2, y2, x, y, color);
			shape.draw();
			shapes.add(shape);
			f = 1;

		}
		// ����������
		if ("����������".equals(str)) {
			shape = new ImpInteTract(600, 100, 220, 700, 900, 700, 10, g, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("��������".equals(str)) {
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
		if ("�����".equals(str)) {
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

		// ɫ�ӵ�ʵ�ַ���
		if ("ɫ��".equals(str)) {
			shape = new ImpColorzi(g, color);
			shape.draw();
			shapes.add(shape);
		}

		if ("��������".equals(str)) {
			shape = new ImpInteF(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// �������ζ�
		if ("�ִ�����".equals(str)) {
			shape = new ImpNowF(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// ����Ҷ
		if ("��Ҷ".equals(str)) {
			shape = new ImpLeaf(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// ����ʲô��
		if ("mandelbrot��".equals(str)) {
			shape = new ImpMandelrot(g, color);
			shape.draw();
			shapes.add(shape);
		}

		// ����
		if ("����".equals(str)) {
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

	// ����ͷ�ʱ�Ĵ�����
	public void mouseReleased(MouseEvent e) {

		// ��¼����ͷ�ʱ������
		if (f == 1) {
			x2 = e.getX();
			y2 = e.getY();
		}
		// ��������
		if ("��������".equals(str)) {
			shape = new ImpInteLine(x1, y1, x2, y1, g, color);
			shape.draw();
			shapes.add(shape);
		}

		// ������
		if ("����".equals(str)) {
			shape = new ImpFillRact(g, x1, y1, x2, y2, color);
			shape.draw();
			shapes.add(shape);
		}
		// �������
		if ("�����".equals(str)) {
			shape = new ImpFiveXing(x1, y1, x2, y2, g, color);
			shape.draw();
			shapes.add(shape);
		}

		// ��������ĵõ��ˣ���������ֱ�ߵĻ��ƣ����û�������g�������ڽ������滭��ֱ��
		if ("��ֱ��".equals(str)) {
			shape = new ImpLine(g, x1, y1, x2, y2, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("����Բ".equals(str)) {
			shape = new ImpOval(g, x1, y1, x2, y2, color);
			shape.draw();
			shapes.add(shape);
		}
		if ("������".equals(str) && f == 1) {
			g.setColor(color);
			g.drawLine(x1, y1, x2, y2);
			f++;
		}
		if ("��������".equals(str) && f == 1) {
			g.setColor(color);
			g.drawLine(x1, y1, x2, y2);
			shape.draw();
			shapes.add(shape);
			f++;
		}
		if ("�����".equals(str) && f == 1) {
			shape = new ImpPolygon(g, x1, y1, x2, y2, x1, y1, color);
			shape.draw();
			shapes.add(shape);
			f++;
		}
		int r = Math.abs(x1 - x2);
		if ("������".equals(str)) {
			for (int i = r; i > 0; i--) {
				shape = new ImpFillOval(g, x1 += 1, y1 += 1, x2 -= 1, y2 -= 1,
						color);
				shape.draw();
				shapes.add(shape);
			}
		}

		if ("�������".equals(str)) {
			for (int i = 0; i < 4; i++) {
				shape = new Imp3DRact(g, x1 += 4, y1 += 4, x2 -= 4, y2 -= 4,
						color);
				shape.draw();
				shapes.add(shape);
			}
		}
		if ("����Բ".equals(str)) {
			for (int i = 0; i < 4; i++) {
				shape = new Imp3DOval(g, x1 += 10, y1 += 10, x2 -= 10,
						y2 -= 10, color);
				shape.draw();
				shapes.add(shape);
			}
		}

		if ("����".equals(str)) {
			for (int i = 0; i < 5; i++) {
				shape = new ImpManyLine(g, x1 += 22, y1 -= 10, x2 -= 15,
						y2 -= 10, color);
				shape.draw();
				shapes.add(shape);
			}
		}

	}

	// ������ʱ�Ĵ�����
	public void mouseEntered(MouseEvent e) {

	}

	// ����˳�ʱ�Ĵ�����
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

	// ����϶�ʱ�Ĵ�����
	public void mouseDragged(MouseEvent e) {
		if ("������".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpCur(g, x1, y1, x, y, color);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}
		if ("�϶���".equals(str)) {
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
		if ("��Ƥ��".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpEraser(g, x1, y1, x, y);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}
		if ("��ˢ".equals(str)) {
			int x, y;
			x = e.getX();
			y = e.getY();
			shape = new ImpBrush(g, x1, y1, x, y, color);
			shape.draw();
			shapes.add(shape);
			x1 = x;
			y1 = y;
		}
		if ("��ǹ".equals(str)) {
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

	// ����ͷ�ʱ���ƶ�����
	public void mouseMoved(MouseEvent e) {

	}

	// �������ߵ��㷨
	public void drawInteLine(int x1, int y1, int x2, int y2, Graphics g) {
		if ((x2 - x1) > 4) {
			drawInteLine(x1, y1 + 20, x1 + (x2 - x1) / 3, y2 + 20, g);
			drawInteLine(x2 - (x2 - x1) / 3, y1 + 20, x2, y2 + 20, g);
		}
		g.drawLine(x1, y1, x2, y2);
	}

	// ������������
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

	// ������л����˹����̺
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
	 * ��������
	 * @param t������0<=t<12pi
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
