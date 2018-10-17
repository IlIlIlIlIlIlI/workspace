package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;
import com.util.NetJavaShape;

public class ImpTree implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpTree(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		double x1, y1, x2, y2, x, y;
		double a[] = { 0.1950, 0.4620, -0.6370, -0.0350, -0.0580 };
		double b[] = { -0.4880, 0.4140, 0.0000, 0.0700, -0.0700 };
		double c[] = { 0.3440, -0.2520, 0.0000, -0.4690, 0.4530 };
		double d[] = { 0.4430, 0.3610, 0.5010, 0.0220, -0.1110 };
		double e1[] = { 0.4431, 0.2511, 0.8562, 0.4884, 0.5976 };
		double f[] = { 0.2452, 0.5692, 0.2512, 0.5069, 0.0969 };
		x1 = 0;
		y1 = 0;
		Random random1 = new Random();

		for (int i = 0; i < 100000; i++) {
			int r = -1;
			r = random1.nextInt(100);
			// g.setColor(Color.GREEN);
			if (i % 10000 == 0)
				g.setColor(new Color(random1.nextInt(256), random1
						.nextInt(256), random1.nextInt(256)));
			if (r >= 0 && r < 20) {
				// g.setColor(Color.BLUE);
				x2 = (a[0]) * x1 + (b[0]) * y1 + (e1[0]);
				y2 = (c[0]) * x1 + (d[0]) * y1 + (f[0]);
				x1 = x2;
				y1 = y2;
				x = x2 * 500 + 400;
				y = y2 * 500 + 400;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r >= 20 && r < 40) {
				// g.setColor(Color.GREEN);
				x2 = (a[1]) * x1 + (b[1]) * y1 + (e1[1]);
				y2 = (c[1]) * x1 + (d[1]) * y1 + (f[1]);
				x1 = x2;
				y1 = y2;
				x = x2 * 500 + 400;
				y = y2 * 500 + 400;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r >= 40 && r < 60) {
				// g.setColor(Color.ORANGE);
				x2 = (a[2]) * x1 + (b[2]) * y1 + (e1[2]);
				y2 = (c[2]) * x1 + (d[2]) * y1 + (f[2]);
				x1 = x2;
				y1 = y2;
				x = x2 * 500 + 400;
				y = y2 * 500 + 400;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r >= 60 && r < 80) {
				// g.setColor(Color.BLACK);
				x2 = (a[3]) * x1 + (b[3]) * y1 + (e1[3]);
				y2 = (c[3]) * x1 + (d[3]) * y1 + (f[3]);
				x1 = x2;
				y1 = y2;
				x = x2 * 500 + 400;
				y = y2 * 500 + 400;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
			if (r >= 80) {
				// g.setColor(Color.BLACK);
				x2 = (a[4]) * x1 + (b[4]) * y1 + (e1[4]);
				y2 = (c[4]) * x1 + (d[4]) * y1 + (f[4]);
				x1 = x2;
				y1 = y2;
				x = x2 * 500 + 400;
				y = y2 * 500 + 400;
				y = 1000 - y;
				g.drawLine((int) x, (int) y, (int) x, (int) y);
			}
		}
	}
}
