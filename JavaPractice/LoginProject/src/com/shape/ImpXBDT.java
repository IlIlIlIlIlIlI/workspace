package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpXBDT implements NetJavaShape{
	
	private int x,y,d,n;
	private Graphics g;
	private Color color;
	

	public ImpXBDT(int x, int y, int d, int n, Graphics g, Color color) {
		super();
		this.x = x;
		this.y = y;
		this.d = d;
		this.n = n;
		this.g = g;
		this.color=color;
	}


	public void draw() {
		g.setColor(color);
		drawXBRact(x,y,d,g,n);
	}
	
	// 迭代画谢尔宾斯基地毯
	public void drawXBRact(int x, int y, int d, Graphics g,int n) {
		if(n>0){
			n--;
			int x1,y1,Ind;
			int x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8;
			Ind=d/3;
			x1=x+Ind;
			y1=y+Ind;
			g.fillRect(x1, y1, Ind, Ind);
			x2=x+Ind;
			y2=y;
			x3=x+2*Ind;
			y3=y;
			x4=x;
			y4=y+Ind;
			x5=x;
			y5=y+Ind*2;
			x6=x+Ind;
			y6=y+Ind*2;
			x7=x+Ind*2;
			y7=y+Ind*2;
			x8=x+Ind*2;
			y8=y+Ind;
			drawXBRact( x, y, Ind, g,n);
			drawXBRact( x2, y2, Ind, g,n);
			drawXBRact( x3, y3, Ind, g,n);
			drawXBRact( x4, y4, Ind, g,n);
			drawXBRact( x5, y5, Ind, g,n);
			drawXBRact( x6, y6, Ind, g,n);
			drawXBRact( x7, y7, Ind, g,n);
			drawXBRact( x8, y8, Ind, g,n);
			}
		}

}
