package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpFillRact implements NetJavaShape{
	Graphics g;
	int x1, y1,x2, y2;
	Color c;
	public ImpFillRact(Graphics g,int x1,int y1,int x2,int y2,Color c){
		this.g=g;
		this.c=c;
		this.x1=Math.min(x1, x2);
		this.y1=Math.min(y1, y2);
		this.x2=Math.abs(x1-x2);
		this.y2=Math.abs(y1-y2);
	}
	public void draw() {
		g.setColor(c);
		g.fillRect(x1, y1, x2, y2);
	}

}
