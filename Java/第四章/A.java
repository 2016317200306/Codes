package admin;

public class A {
	//因为前面有返回类型，所以不是构造方法
	//此为构造方法的多态
	void A() {
		System.out.println("Class A");
	}
	public static void main(String args[]) {
		new A();
	}
}
