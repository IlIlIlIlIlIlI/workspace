package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import com.util.NetJavaShape;

public class ImpNowF implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpNowF(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		double x1, y1, x2, y2, x, y;
		x1 = 0;
		y1 = 0;
		Random random = new Random();
		for (int i = 0; i < 100000; i++) {
			if (i % 10000 == 0)
				g.setColor(new Color(random.nextInt(256), random
						.nextInt(256), random.nextInt(256)));
			x2 = y1 - Math.signum(x1) * Math.sqrt(Math.abs(1 * x1));
			y2 = 0.4 - x1;
			x1 = x2;
			y1 = y2;
			x = x2 * 100 + 500;
			y = y2 * 100 + 500;
			g.drawLine((int) x, (int) y, (int) x, (int) y);
		}
	}

}
