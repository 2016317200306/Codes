package admin;

class AddClass {
	public int x = 0,y = 0,z = 0;
	AddClass(int x) {
		this.x = x;
	}
	
	AddClass(int x,int y) {
		this(x);//调用第一个构造方法
		this.y = y;
	}
	
	AddClass(int x,int y,int z) {
		this(x,y);//调用第二个构造方法
		this.z = z;
	}
	
	public int add() {
		return x + y + z;
	}
}

public class RunAddClass {
	public static void main(String[] args) {
		AddClass p1 = new AddClass(2,3,5);
		AddClass p2 = new AddClass(10,20);
		AddClass p3 = new AddClass(1);
		System.out.println("x + y + z = " + p1.add());
		System.out.println("x + y = " + p2.add());
		System.out.println("x = " + p3.add());
	}
}
