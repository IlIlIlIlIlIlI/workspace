package com.cbs;

import java.awt.Dimension;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Login {
	
	public void showUI(){
		JFrame jf=new JFrame("Login");
		jf.setSize(200, 300);
		jf.setDefaultCloseOperation(3);
		jf.setLocationRelativeTo(null);
		FlowLayout layout=new FlowLayout(FlowLayout.LEADING,10,20);
		jf.setLayout(layout);
		JLabel jname=new JLabel("ÕËºÅ£º");
		jf.add(jname);
		JTextField nameValue=new JTextField();
		nameValue.setPreferredSize(new Dimension(120,20));
		jf.add(nameValue);
		JLabel jpassword =new JLabel("ÃÜÂë£º");
		jf.add(jpassword);
		JTextField passwordValue=new JTextField();
		passwordValue.setPreferredSize(new Dimension(120,20));
		jf.add(passwordValue);
		JButton b1=new JButton("µÇÂ¼");
		jf.add(b1);
		jf.setVisible(true);
		//Ìí¼Ó¼àÌý
		LoginListener ll = new LoginListener();
		ll.setJ1(nameValue);
		ll.setJ2(passwordValue);
		b1.addActionListener(ll);
		
	}
}
