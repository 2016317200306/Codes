package admin;

public class AccessValue {
	int value;
	//main是特殊的静态方法
	public static void main(String[] args) {
		for(int i = 0;i < args.length;i++) {
			System.out.println(args[i]);
		}
	}

}
