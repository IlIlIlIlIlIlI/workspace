package Heart;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;

public class DrawHeart extends JFrame {

	public static void main(String[] args) {
		DrawHeart dh = new DrawHeart();
		dh.showUI();
	}

	// 初始化窗体界面
	public void showUI() {
		this.setTitle("Forver Heart");
		this.setSize(500, 500);
		this.getContentPane().setBackground(Color.BLACK);
		this.setDefaultCloseOperation(3);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}

	public void paint(Graphics g) {
		super.paint(g);

		for (int i = 0; i <= 180; i++) 
			for (int j = 0; j <= 180; j++) {
				double r = Math.PI / 45 * i * (1 - Math.sin(Math.PI / 45 * j))
						* 20;
				double x = r * Math.cos(Math.PI / 45 * j)
						* Math.sin(Math.PI / 45 * i) + 300;
				double y = -r * Math.sin(Math.PI / 45 * j) + 200;
				Color c = Color.getHSBColor(i * j / 8100.0f, 0.9999f, 0.9999f);
				g.setColor(c);
				g.drawOval((int) x, (int) y, 1, 1);
				try {
					Thread.sleep(10);
				} catch (Exception e) {
				}
			}
	}
}
