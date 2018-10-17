package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import com.util.NetJavaShape;

public class ImpLeaf implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpLeaf(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		g.setColor(c);
		double x1, y1, x2, y2, x, y;
		double a[] = { 0.0, 0.2, -0.15, 0.85 };
		double b[] = { 0.0, -0.26, 0.28, 0.04 };
		double c[] = { 0.0, 0.23, 0.26, -0.04 };
		double d[] = { 0.16, 0.22, 0.24, 0.85 };
		double e1[] = { 0.0, 0.0, 0.0, 0.0 };
		double f[] = { 0.0, 1.6, 0.44, 1.6 };
		x1 = 0;
		y1 = 0;
		Random random = new Random();

		for (int i = 0; i < 100000; i++) {
			int r = -1;
			r = random.nextInt(100);
			g.setColor(Color.GREEN);
			// if(i%10000==0)
			// g.setColor(new
			// Color(random.nextInt(256),random.nextInt(256),random.nextInt(256)));
			if (r == 0) {
				x2 = (a[0]) * x1 + (b[0]) * y1 + (e1[0]);
				y2 = (c[0]) * x1 + (d[0]) * y1 + (f[0]);
				x1 = x2;
				y1 = y2;
				x = x2 * 30 + 300;
				y = y2 * 30 + 500;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r > 0 && r < 8) {
				x2 = (a[1]) * x1 + (b[1]) * y1 + (e1[1]);
				y2 = (c[1]) * x1 + (d[1]) * y1 + (f[1]);
				x1 = x2;
				y1 = y2;
				x = x2 * 30 + 300;
				y = y2 * 30 + 500;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r >= 8 && r < 15) {
				x2 = (a[2]) * x1 + (b[2]) * y1 + (e1[2]);
				y2 = (c[2]) * x1 + (d[2]) * y1 + (f[2]);
				x1 = x2;
				y1 = y2;
				x = x2 * 30 + 300;
				y = y2 * 30 + 500;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r >= 15) {
				x2 = (a[3]) * x1 + (b[3]) * y1 + (e1[3]);
				y2 = (c[3]) * x1 + (d[3]) * y1 + (f[3]);
				x1 = x2;
				y1 = y2;
				x = x2 * 30 + 300;
				y = y2 * 30 + 500;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
		}
	}
}
