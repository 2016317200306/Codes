package admin;

class IntClass {
	int value;
	//定义构造方法将属性value初始化，注意构造方法没有返回类型
	public IntClass(int val) {
		value = val;
	}
}

public class IntClassConstructor {
	public static IntClass getInstance() {
		//调用构造方法，从而省略s.value方法
		IntClass s = new IntClass(8);
		//s.value = 8;
		return s;
	}
	
	public static void main(String[] args) {
		IntClass a = getInstance();
		System.out.println(a.value);
	}
}
