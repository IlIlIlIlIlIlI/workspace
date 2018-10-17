package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import com.util.NetJavaShape;

public class ImpMandelrot implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpMandelrot(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		g.setColor(c);
		Complex origin = new Complex(-0.5, 0);
		double curScale = 0.8;
		drawMand(origin, curScale, 300);
	}
	
	// 求最大的迭代次数的算法，时间逃逸算法
		public int mand(Complex z, int maxIte) {
			Complex curComp = new Complex(0, 0);
			for (int i = 0; i < maxIte; i++) {
				if (curComp.modulus() > 2)
					return i;
				curComp = curComp.mul(curComp).add(z);
			}
			return maxIte;
		}
		
	// 画图的算法
		public void drawMand(Complex z, double scale, int MaxIte) {
			double pixUnit = 3 / (1080 * scale);
			double startx = z.r - 1080 * pixUnit / 2;
			double starty = z.i - 720 * pixUnit / 2;

			for (int i = 0; i < 2550; i++) {//1080
				for (int j = 0; j < 2550; j++) {//720
					double x0 = startx + i * pixUnit;
					double y0 = starty + j * pixUnit;
					Complex curComplex = new Complex(x0, y0);
					int time = mand(curComplex, MaxIte);
					if (time == MaxIte) {
						double x = x0 * 150 + 500;// 扩大出现方格
						double y = y0 * 150 + 500;
						g.drawLine((int) x, (int) y, (int) x, (int) y);
					}
				}
			}
		}
}
