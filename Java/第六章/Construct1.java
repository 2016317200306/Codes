package admin;

class Pare {
	int i = 3;
	Pare() {}
}

public class Construct extends Pare{
	int i = 8;
	Construct() {}
	Construct(int num)	{this();}
	int getSuper()	{return super.i;}
	public static void main(String args[]) {
		Construct ct = new Construct(9);
		System.out.print(ct.i);
		System.out.println(ct.getSuper());
	}
}
