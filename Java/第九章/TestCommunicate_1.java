package admin;

class Account {//账户类
	volatile private int value;//账户金额
	volatile private boolean isMoney = false;
	
	synchronized void put(int i) {
		if(isMoney) {
			try{
				wait();
			}catch(Exception e) {}
		}
		
		value += i;//存入金额
		System.out.println("存入" + i + " 账上金额为：" + value);
		
		isMoney = true;
		notify();
	}
	
	synchronized int get(int i) {//取出金额i返回实际取得的金额
		if(!isMoney) {
			try{wait();}
			catch(Exception e)	{}
		}
		
		if(value > i)	value -= i;
		else {//金额不足时，取走全部钱
			i = value;
			value = 0;
		}
		System.out.println("取走" + i + "账上金额为：" + value);
		
		isMoney = false;
		notify();
		
		return i;
	}
}

class Save implements Runnable {
	private Account a1;
	public Save(Account a1) {
		this.a1 = a1;
	}
	
	public void run() {
		while(true) {
			a1.put(100);
		}
	}
}

class Fetch implements Runnable {
	private Account a1;
	public Fetch(Account a1) {
		this.a1 = a1;
	}
	
	public void run() {
		while(true) {
			a1.get(100);
		}
	}
}

public class TestCommunicate_1 {
	public static void main(String[] args) {
		Account a1 = new Account();
		new Thread(new Save(a1)).start();
		new Thread(new Fetch(a1)).start();
	}
}
