package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import com.util.NetJavaShape;

public class ImpPgun implements NetJavaShape {
	Graphics g;
	int x1, y1;
	Color c;

	public ImpPgun(Graphics g, int x1, int y1, Color c) {
		this.g = g;
		this.c = c;
		this.x1 = x1;
		this.y1 = y1;
	}

	public void draw() {
		g.setColor(c);
		Random random = new Random();
		for (int i = 0; i < random.nextInt(10); i++) {
			g.drawLine(x1 + random.nextInt(4), y1 + random.nextInt(4), x1
					+ random.nextInt(4), y1 + random.nextInt(4));
		}
	}

}
