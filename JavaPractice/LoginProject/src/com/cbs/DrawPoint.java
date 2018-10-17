package com.cbs;

import java.awt.Point;

/**
 * 返回分形中需要经过的点
 */
public class DrawPoint {
	private String sequence;//分形序列
	private double ra,rb;//ra便是+转过的弧度，rb表示-转过的弧度
	
	//a表示+转过的角度，b表示-转过的角度
	public DrawPoint(String sequence,int a,int b ){
		this.sequence=sequence;
		ra=a*Math.PI/180;
		rb=b*Math.PI/180;
	}
	
	//将分形序列处理成点的数组，并画出分形适合的宽为W,高为H的画布
	public Point[] process(int W,int H){
		//len线段长度，向前走的距离
		double len=10.0;
		//(x0,y0)表示方向的单位向量
		double x0=1.0,y0=0.0;
		//(x1,y1)表示当前的点
		double x1=0,y1=0;
		double min_x,max_y,min_y,max_x;
		min_x=max_x=x1;
		min_y=max_y=y1;
		for(int i=0;i<sequence.length();i++){
			if(sequence.charAt(i)=='F'){
				double _x1=x1+len*x0;
				double _y1=y1+len*y0;
				x1=_x1;
				y1=_y1;
				if(x1<min_x) min_x=x1;
				if(x1>max_x) max_x=x1;
				if(y1<min_y) min_y=y1;
				if(y1>max_y) max_y=y1;
			}else if(sequence.charAt(i)=='+'){
				double _x0=x0*Math.cos(ra)-y0*Math.sin(ra);
				double _y0=x0*Math.sin(ra)+y0*Math.cos(ra);
				x0=_x0;
				y0=_y0;
			}else if(sequence.charAt(i)=='-'){
				double _x0=x0*Math.cos(-rb)-y0*Math.sin(-rb);
				double _y0=x0*Math.sin(-rb)+y0*Math.cos(-rb);
				x0=_x0;
				y0=_y0;
			}
		}
		
		//r表示放缩比例
		double r=Math.min(W/(max_x-min_x), H/(max_y-min_y));
		//放缩步长
		len*=r;
		//(mid_x,mid_y)为图形的中心位置
		double mid_x=(min_x+max_x)*0.5,mid_y=(min_y+max_y)*0.5;
		//图形中心应该与画布中心重合，依据这点来平移初始坐标
		x1=W*0.5-mid_x*r;
		y1=H*0.5-mid_y*r;
		x0=1.0;
		y0=0;
		//n表示点的个数
		int n=1;
		for(int i=0;i<sequence.length();i++){
			if(sequence.charAt(i)=='F') 
				++n;
		}
		Point points[]=new Point[n];
		points[0]=new Point((int)x1,(int)y1);
		//sign表示点的下标位置
		int sign=1;
		for(int i=0;i<sequence.length();i++){
			if(sequence.charAt(i)=='F'){
				x1=x1+len*x0;
				y1=y1+len*y0;
				points[sign++]=new Point((int)x1+220,(int)y1+220);//加220移动，但是第一个点不会变
			}else if(sequence.charAt(i)=='+'){
				double _x0=x0*Math.cos(ra)-y0*Math.sin(ra);
				double _y0=x0*Math.sin(ra)+y0*Math.cos(ra);
				x0=_x0;
				y0=_y0;
			}else if(sequence.charAt(i)=='-'){
				double _x0=x0*Math.cos(-rb)-y0*Math.sin(-rb);
				double _y0=x0*Math.sin(-rb)+y0*Math.cos(-rb);
				x0=_x0;
				y0=_y0;
			}
		}
		return points;
	}
}
