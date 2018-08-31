package admin;

import java.awt.*;
import java.applet.*;

abstract class Shapes {
	protected int x,y,k;
	protected double m;
	public Shapes(int x,int y,int k,double m) {
		this.x = x;
		this.y = y;
		this.k = k;
		this.m = m;
	}
	
	abstract public double getArea();
	abstract public double getPerimeter();
	
}

class Rect extends Shapes {
	public double getArea() {
		return k * m;
	}
	
	public double getPerimeter() {
		return (2 * k + 2 * m);
	}
	
	public Rect(int x,int y,int width,int height) {
		super(x,y,width,height);
	}
}

class Triangle extends Shapes {
	public double getArea() {
		return (Math.sqrt(m * (m - k) * (m - x) * (m - y)));
	}
	
	public double getPerimeter() {
		return k + x + y;
	}
	
	public Triangle(int baseA,int baseB,int baseC) {
		super(baseA,baseB,baseC,0);
		m = (baseA + baseB + baseC) / 2.0;
	}
}

class Circle extends Shapes {
	public double getArea() {
		return (m * m * Math.PI);
	}
	
	public double getPerimeter() {
		return 2 * Math.PI * m;
	}
	
	public Circle(int x,int y,int width) {
		//m为半径，k为直径
		super(x,y,width,width / 2.0);
	}
}

public class RunShape extends Applet{
	Rect rect = new Rect(5,15,25,25);
	Triangle tri = new Triangle(5,5,8);
	Circle cir = new Circle(13,90,25);
	public void paint(Graphics g) {
		//绘制图形，输出面积和边长
		g.drawRect(rect.x, rect.y, rect.k, (int)rect.m);
		g.drawString("Rect Area: " + rect.getArea(), 50, 35);
		g.drawString("Rect Perimeter: " + rect.getPerimeter(), 50, 55);
		//输出三角形面积和边长
		g.drawString("Triangle Area: " + tri.getArea(), 50, 75);
		g.drawString("Triangle Perimeter" + tri.getPerimeter(), 50, 95);
		//绘制圆，输出面积和边长
		g.drawOval(cir.x - (int)cir.k / 2, cir.y - (int)cir.k / 2, cir.k, cir.k);
		g.drawString("Circle Area:" + cir.getArea(), 50, 115);
		g.drawString("Circle Perimeter:" + cir.getPerimeter(), 50, 135);
	}
}
