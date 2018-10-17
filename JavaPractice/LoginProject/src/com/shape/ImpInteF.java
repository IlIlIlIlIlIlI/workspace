package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import com.util.NetJavaShape;

public class ImpInteF implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpInteF(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		g.setColor(c);
		double x2, y2, x1, y1, x3, y3;
		x1 = 0;
		y1 = 0;
		Random random = new Random();
		// drawShape(1000,0,0);//迭代会把信息存入栈中，因为栈的容量有限，所以不能设太大的n
		for (int i = 0; i < 100000; i++) {
			if (i % 10000 == 0)
				g.setColor(new Color(random.nextInt(256), random
						.nextInt(256), random.nextInt(256)));
			x2 = (Math.sin(-2.0 * y1) - Math.cos(-2.0 * x1));
			y2 = (Math.sin(-1.2 * x1) - Math.cos(2.0 * y1));
			// x2= -5.65*(Math.sin(1.40*y1)-Math.cos(1.56*x1));
			// y2= 1.40*(Math.sin(1.40*x1)-Math.cos(1.56*y1));
			// 把得出的值作为下一次计算的因子
			x1 = x2;
			y1 = y2;
			x3 = x2 * 100 + 500;
			y3 = y2 * 100 + 500;
			g.drawLine((int) x3, (int) y3, (int) x3, (int) y3);
		}
	}

}
