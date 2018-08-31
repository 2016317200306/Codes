package admin;

public class Fibonacci {
	public static int fseq(int n) {
		if(n < 1)	return -1;
		if(n == 1 || n == 2)	return 1;
		else return fseq(n - 1) + fseq(n - 2);
	}
	
	public static void main(String args[]) {
		System.out.println(fseq(10));
	}
}
