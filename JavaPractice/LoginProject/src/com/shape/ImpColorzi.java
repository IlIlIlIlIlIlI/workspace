package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

import com.util.NetJavaShape;

public class ImpColorzi implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpColorzi(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		g.setColor(c);
		Random random = new Random();
		int xa = 220, xb = 220, xc = 650, pointx = 650;
		int ya = 100, yb = 650, yc = 100, pointy = 650;
		g.drawLine(pointx, pointy, pointx, pointy);
		for (int i = 0; i < 100000; i++) {
			int sign = random.nextInt(3);
			if (sign == 0) {
//				pointx = (xa + pointx) / 2;
//				pointy = (ya + pointy) / 2;
				pointx = (xa + pointx) / 3;
				pointy = (ya + pointy) / 3;
				g.drawLine(pointx, pointy, pointx, pointy);
			}
			if (sign == 1) {
//				pointx = (xb + pointx) / 2;
//				pointy = (yb + pointy) / 2;
				pointx = (xb + pointx) / 4;
				pointy = (yb + pointy) / 4;
				g.drawLine(pointx, pointy, pointx, pointy);
			}
			if (sign == 2) {
//				pointx = (xc + pointx) / 2;
//				pointy = (yc + pointy) / 2;
				pointx = (xc + pointx) / 2;
				pointy = (yc + pointy) / 2;
				g.drawLine(pointx, pointy, pointx, pointy);
			}

		}
	}

}
