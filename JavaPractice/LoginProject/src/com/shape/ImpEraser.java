package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpEraser implements NetJavaShape{
	Graphics g;
	int x1, y1,x2, y2;
	public ImpEraser(Graphics g,int x1,int y1,int x2,int y2){
		this.g=g;
		this.x1=x1;
		this.y1=y1;
		this.x2=x2;
		this.y2=y2;
	}
	public void draw() {
		g.setColor(Color.WHITE);
		g.fillRect(x1, y1, 50, 50);
	}

}
