package com.cbs;


/**
 * Ö÷Àà
 * @author CBS
 *
 */
public class MyPaint {

	public static void main(String[] args) {
//		Login login=new Login();
//		login.showUI();
		Draw draw=new Draw();
		draw.showUI();
//		MyPaint m=new MyPaint();
//		m.DrawBuf();
	}
	
	public void DrawBuf(){
		double x,y;
		for(int t=0;t<=1000;t++){
			x=Math.sin(t)*(Math.pow(Math.E, Math.cos(t)-2*Math.cos(t*4)-Math.pow(Math.sin(t/12.0), 5)));
			y=Math.cos(t)*(Math.pow(Math.E, Math.cos(t)-2*Math.cos(t*4)-Math.pow(Math.sin(t/12.0), 5)));
		}
	}

}
