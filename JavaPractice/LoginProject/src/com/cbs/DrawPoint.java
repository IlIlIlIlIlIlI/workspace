package com.cbs;

import java.awt.Point;

/**
 * ���ط�������Ҫ�����ĵ�
 */
public class DrawPoint {
	private String sequence;//��������
	private double ra,rb;//ra����+ת���Ļ��ȣ�rb��ʾ-ת���Ļ���
	
	//a��ʾ+ת���ĽǶȣ�b��ʾ-ת���ĽǶ�
	public DrawPoint(String sequence,int a,int b ){
		this.sequence=sequence;
		ra=a*Math.PI/180;
		rb=b*Math.PI/180;
	}
	
	//���������д���ɵ�����飬�����������ʺϵĿ�ΪW,��ΪH�Ļ���
	public Point[] process(int W,int H){
		//len�߶γ��ȣ���ǰ�ߵľ���
		double len=10.0;
		//(x0,y0)��ʾ����ĵ�λ����
		double x0=1.0,y0=0.0;
		//(x1,y1)��ʾ��ǰ�ĵ�
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
		
		//r��ʾ��������
		double r=Math.min(W/(max_x-min_x), H/(max_y-min_y));
		//��������
		len*=r;
		//(mid_x,mid_y)Ϊͼ�ε�����λ��
		double mid_x=(min_x+max_x)*0.5,mid_y=(min_y+max_y)*0.5;
		//ͼ������Ӧ���뻭�������غϣ����������ƽ�Ƴ�ʼ����
		x1=W*0.5-mid_x*r;
		y1=H*0.5-mid_y*r;
		x0=1.0;
		y0=0;
		//n��ʾ��ĸ���
		int n=1;
		for(int i=0;i<sequence.length();i++){
			if(sequence.charAt(i)=='F') 
				++n;
		}
		Point points[]=new Point[n];
		points[0]=new Point((int)x1,(int)y1);
		//sign��ʾ����±�λ��
		int sign=1;
		for(int i=0;i<sequence.length();i++){
			if(sequence.charAt(i)=='F'){
				x1=x1+len*x0;
				y1=y1+len*y0;
				points[sign++]=new Point((int)x1+220,(int)y1+220);//��220�ƶ������ǵ�һ���㲻���
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
