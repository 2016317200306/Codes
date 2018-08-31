package admin;

class Pare{
	int i;
	Pare()	{i = 6;}
}

public class Construct extends Pare{
	Construct()	{}
	Construct(int num)	{}
	public static void main(String[] args) {
		Construct ct = new Construct(9);//隐式调用父类构造函数
		System.out.println(ct.i);
	}
}
