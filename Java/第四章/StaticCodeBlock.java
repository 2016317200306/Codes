package admin;

public class StaticCodeBlock {
	static int value;
	static {
		value = 3;
		System.out.println("value = " + value);
	}
	public static void main(String[] args) {}

}
