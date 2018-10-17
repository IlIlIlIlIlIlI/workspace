package com.shape;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import com.cbs.DrawPoint;
import com.cbs.Fractal;
import com.util.NetJavaShape;

public class ImpLSystem implements NetJavaShape{
	Graphics g;
	Color c;
	public ImpLSystem(Graphics g,Color c){
		this.g=g;
		this.c=c;
	}
	public void draw() {
		try {
			Fractal fractal = new Fractal("F+F+F+F", "FF+F+F+F+FF");
//			System.out.println(fractal.generate(4));
			DrawPoint drawpoint = new DrawPoint(fractal.generate(4), 90,
					90);
			Point points[] = drawpoint.process(500, 500);
			for (int i = 0; i < points.length-1; i++) {
				g.drawLine(points[i].x, points[i].y, points[i + 1].x,
						points[i + 1].y);
			}
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}
}
