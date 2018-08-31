package admin;

import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class MyApplet extends Applet implements ActionListener{
	private TextField input;
	private double d = 0.0;
	public void init() {
		input = new TextField(10);
		
		add(input);
		
		input.addActionListener(this);
	}
	
	public void paint(Graphics g) {
		g.drawString("您输入了数据" + d, 10, 50);
	}
	
	public void actionPerformed(ActionEvent e) {
		
		d = Double.valueOf(input.getText()).doubleValue();
		
		repaint();
	}
}
