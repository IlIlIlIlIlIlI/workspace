package com.cbs;

import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class MouseTest implements MouseMotionListener{
	Graphics g;
	public MouseTest(Graphics g){
		this.g=g;
	}

	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		int x,y;
		x=e.getX();
		y=e.getY();
		
	}

}
