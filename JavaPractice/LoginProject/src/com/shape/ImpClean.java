package com.shape;

import java.awt.Color;
import java.awt.Graphics;

import com.util.NetJavaShape;

public class ImpClean implements NetJavaShape {
	
	private Graphics g;

	public ImpClean(Graphics g) {
		this.g = g;
	}

	public void draw() {
		g.setColor(Color.WHITE);
		g.fillRect(0, 0, 970, 800);
	}

}
