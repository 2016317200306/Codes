package admin;

class IntClass {
	int value;
}

public class RunIntClass {

	public static void modifyValue(IntClass s,int val) {
		s.value = val;
	}
	
	public static IntClass getInstance() {
		//�ڷ����в�������
		IntClass s = new IntClass();
		s.value = 8;
		return s;
	}
	
	public static void main(String[] args) {
		IntClass a = new IntClass();
		modifyValue(a,8);
		System.out.println(a.value);
		
		//���¸������
		a = getInstance();
		System.out.println(a.value);
	}

}
