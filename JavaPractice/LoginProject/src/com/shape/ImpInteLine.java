package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpInteLine implements NetJavaShape {
	private int x1, y1, x2, y2;
	private Graphics g;
	private Color color;
	

	public ImpInteLine(int x1, int y1, int x2, int y2, Graphics g, Color color) {
		super();
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
		this.g = g;
		this.color = color;
	}


	public void draw() {
		g.setColor(color);
		drawInteLine(x1, y1, x2, y2, g);

	}
	// 迭代画线的算法
		public void drawInteLine(int x1, int y1, int x2, int y2, Graphics g) {
			if ((x2 - x1) > 4) {
				drawInteLine(x1, y1 + 20, x1 + (x2 - x1) / 3, y2 + 20, g);
				drawInteLine(x2 - (x2 - x1) / 3, y1 + 20, x2, y2 + 20, g);
			}
			g.drawLine(x1, y1, x2, y2);
		}


}
