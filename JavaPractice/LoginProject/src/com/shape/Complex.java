package com.shape;

public class Complex {
	
	public double r;
	public double i;
	
	public Complex(double real,double image){
		this.r=real;
		this.i=image;
	}
	//取复数的模
	public double modulus(){
		return Math.sqrt(r*r+i*i);
	}
	//复数的加法
	public Complex add(Complex z){
		double addr=r+z.r;
		double addi=i+z.i;
		return new Complex(addr,addi);
	}
	//复数的乘法
	public Complex mul(Complex z){
		double mulr=r*z.r-i*z.i;
		double muli=i*z.r+r*z.i;
		return new Complex(mulr,muli);
	}
}
