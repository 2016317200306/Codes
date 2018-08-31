package admin;

public class PassPara {
	private static int a;
	public static void main(String[] args) {
		modify(a);
		System.out.println(a);
	}
	
	public static void modify(int a) {
		a++;//´Ëa·Ç±Ëa
	}
}
