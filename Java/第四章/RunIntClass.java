package admin;

class IntClass {
	int value;
}

public class RunIntClass {

	public static void modifyValue(IntClass s,int val) {
		s.value = val;
	}
	
	public static IntClass getInstance() {
		//在方法中产生对象
		IntClass s = new IntClass();
		s.value = 8;
		return s;
	}
	
	public static void main(String[] args) {
		IntClass a = new IntClass();
		modifyValue(a,8);
		System.out.println(a.value);
		
		//重新赋予对象
		a = getInstance();
		System.out.println(a.value);
	}

}
