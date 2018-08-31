package admin;

public class ArrayTranspose {

	public static void transpose(int[][] m) {
		if(m == null)	return;
		int temp;
		for(int i = 0;i < m.length;i++) {
			for(int j = 0;j < m.length;j++) {
				if(i > j) {
					temp = m[i][j];
					m[i][j] = m[j][i];
					m[j][i] = temp;
				}
			}
		}
	}
	
	public static void print(int[][] m) {
		if(m == null)	return;
		for(int i = 0;i < m.length;i++) {
			for(int j = 0;j < m.length;j++) {
				System.out.print(m[i][j] + " ");
			}
			System.out.println("");
		}
	}
	
	public static void main(String[] args) {
		int[][] t = {{1,2,3},{4,5,6},{7,8,9}};
		print(t);
		transpose(t);
		System.out.println("转置后的矩阵为:");
		print(t);
	}

}
