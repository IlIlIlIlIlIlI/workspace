package com.cbs;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/*
 * 事件处理类，对窗口事件进行处理
 */

public class LoginListener implements ActionListener {

	JTextField j1,j2;
	
	public void setJ1(JTextField j){
		j1 = j;
	}
	public void setJ2(JTextField j){
		j2= j;
	}
	
	//重写接口抽象方法
	public void actionPerformed(ActionEvent e) {
		if(j1.getText().equals("cbs") && j2.getText().equals("123456")){
			Draw draw=new Draw();
			draw.showUI();
		}else{
			JFrame jf=new JFrame("错误");
			jf.setSize(500,500);
			jf.setDefaultCloseOperation(3);
			jf.setLocationRelativeTo(null);
			JLabel j=new JLabel("输入错误，请重新输入！！");
			jf.add(j);
			jf.setVisible(true);
		}
		
	}

}
