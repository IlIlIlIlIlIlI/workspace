package com.cbs;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/*
 * �¼������࣬�Դ����¼����д���
 */

public class LoginListener implements ActionListener {

	JTextField j1,j2;
	
	public void setJ1(JTextField j){
		j1 = j;
	}
	public void setJ2(JTextField j){
		j2= j;
	}
	
	//��д�ӿڳ��󷽷�
	public void actionPerformed(ActionEvent e) {
		if(j1.getText().equals("cbs") && j2.getText().equals("123456")){
			Draw draw=new Draw();
			draw.showUI();
		}else{
			JFrame jf=new JFrame("����");
			jf.setSize(500,500);
			jf.setDefaultCloseOperation(3);
			jf.setLocationRelativeTo(null);
			JLabel j=new JLabel("����������������룡��");
			jf.add(j);
			jf.setVisible(true);
		}
		
	}

}
