package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpInteTract implements NetJavaShape {
	
	private int x1, y1, x2, y2, x3,  y3,i;
	private Graphics g; 
	private Color color;
	
	

	public ImpInteTract(int x1, int y1, int x2, int y2, int x3, int y3, int i,
			Graphics g, Color color) {
		super();
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
		this.x3 = x3;
		this.y3 = y3;
		this.i = i;
		this.g = g;
		this.color = color;
	}

	public void draw() {
		drawInteTract(x1, y1, x2, y2, x3, y3, g, i);
	}
	
	//µü´ú»­Èý½ÇÐÎ
	public void drawInteTract(int x1, int y1, int x2, int y2, int x3, int y3,
			Graphics g, int i) {
		g.setColor(color);
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

}
