package com.cbs;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import com.util.NetJavaShape;

/**
 * Draw�࣬���ڽ���ĳ�ʼ��
 * 
 * @author CBS
 */
@SuppressWarnings("serial")
public class Draw extends JFrame {
	private Graphics g;
	private DrawListener dl;

	// �����ʼ������
	public void showUI() {
		setTitle("��ͼ");//��������
		setSize(1200, 900);//�����С
		setDefaultCloseOperation(3);
		setLocationRelativeTo(null);//�������
		FlowLayout layout = new FlowLayout(FlowLayout.LEFT);
		setLayout(layout);//����ʹ����ʽ���ֹ�����
		this.setResizable(false);//�����С����

		String buttonName[] = { "��ֱ��", "����Բ", "������", "�����", "��Ƥ��", "�϶���",
				"������", "������", "��ˢ", "��ǹ", "ɫ��", "�������", "����Բ", "��������",
				"��������", "�ִ�����", "��Ҷ", "����", "mandelbrot��", "L-System", "��������",
				"����������", "л����˹����̺", "���ַ�", "���","����" ,"����","�����","����",
				"��������"};
		
		JPanel jp1=new JPanel(new GridLayout(15, 2,10,10));//���ڱ���ͼ�ΰ�ť��ʹ�����񲼾�
		dl = new DrawListener();// ʵ����DrawListener��Ķ���
		for (int i = 0; i < buttonName.length; i++) {
			JButton jbutton = new JButton(buttonName[i]);
			jbutton.addActionListener(dl);// Ϊ��ť��Ӷ�������
			jp1.add(jbutton);
		}
		jp1.setPreferredSize(new Dimension(200, 800));
		this.add(jp1);
		JPanel jp2=new JPanel();//�������
		jp2.setPreferredSize(new Dimension(970, 800));
		jp2.setBackground(Color.WHITE);
		this.add(jp2);

		// ����Color���飬�����洢��ť��Ҫ��ʾ����ɫ��Ϣ
		Color[] colorArray = { Color.BLUE, Color.GREEN, Color.RED, Color.BLACK,
				Color.ORANGE, Color.PINK, Color.CYAN,Color.MAGENTA,Color.DARK_GRAY,
				Color.GRAY,Color.LIGHT_GRAY,Color.YELLOW};
		//���ڱ�����ɫ��ť�����
		JPanel jp3=new JPanel(new GridLayout(1, colorArray.length,3,3));
		// ѭ������colorArray���飬���������е�Ԫ����ʵ������ť����
		for (int i = 0; i < colorArray.length; i++) {
			JButton button = new JButton();
			button.setBackground(colorArray[i]);
			button.setPreferredSize(new Dimension(30, 30));
			//���¼�Դ��ť����ͨ��addActionListener()�����������¼�������dl����󶨡�
			button.addActionListener(dl);
			jp3.add(button);
		}
		this.add(jp3);
		//��Ӱ�ť����Ϊ��ǰ��ɫ
		JButton nowColor=new JButton();
		nowColor.setPreferredSize(new Dimension(40,40));
		nowColor.setBackground(Color.BLACK);//Ĭ�Ϻ�ɫ
		add(nowColor);
		dl.setNowColor(nowColor);
		
		setVisible(true);
		g =jp2.getGraphics();// ��ȡ��ǰ�Ļ���
		dl.setG(g);
		dl.setJ(jp2);
		jp2.addMouseListener(dl);// Ϊ�����������¼���������
		jp2.addMouseMotionListener(dl);// Ϊ�����������ƶ��¼���������
		
	}

	public void paint(Graphics g) {
		// һ��Ҫ�ȵ��ø���Ĺ��췽�����������ƴ���
		super.paint(g);
		for (NetJavaShape shape : dl.getShapes()) {
			shape.draw();
		}
//		for(int i=0;i<dl.getShapes().legnth();i++)
//			dl.getShapes().get(i).draw();

	}

}
