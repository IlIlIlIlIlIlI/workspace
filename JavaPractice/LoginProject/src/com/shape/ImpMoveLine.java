package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpMoveLine implements NetJavaShape{
	Graphics g;
	int x1, y1,x2, y2;
	Color c;
	public ImpMoveLine(Graphics g,int x1,int y1,int x2,int y2,Color c){
		this.g=g;
		this.c=c;
		this.x1=x1;
		this.y1=y1;
		this.x2=x2;
		this.y2=y2;
	}
	public void draw() {
		g.setColor(c);
		g.drawLine(x1, y1, x2, y2);
	}

}
