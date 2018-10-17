package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpFiveXing implements NetJavaShape {
	private int x1, y1, x2, y2;
	private Graphics g;
	private Color color;
	

	public ImpFiveXing(int x1, int y1, int x2, int y2, Graphics g, Color color) {
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
		g.drawLine(x1+(x2-x1)/2, y1, x1+(x2-x1)/4, y2);
		g.drawLine(x1+(x2-x1)/2, y1, x2-(x2-x1)/4, y2);
		g.drawLine(x2, y1+(y2-y1)/2, x1+(x2-x1)/4, y2);
		g.drawLine(x1, y1+(y2-y1)/2, x2-(x2-x1)/4, y2);
		g.drawLine(x2, y1+(y2-y1)/2, x1, y1+(y2-y1)/2);

	}

}
