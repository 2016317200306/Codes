package admin;

class Account {
	volatile private int value;
	volatile private boolean isMoney = false;
	
	synchronized void put(int i) {
		while(isMoney) {
			try{wait();}
			catch(Exception e)	{}
		}
		
		value += i;
		System.out.println("存入" + i + " 账上金额为：" + value);
		isMoney = true;
		notifyAll();
	}
	
	synchronized int get(int i) {
		while(!isMoney) {
			try	{wait();}
			catch(Exception e) {}
		}
		
		if(value > i) value -= i;
		else {
			i = value;
			value = 0;
		}
		System.out.println("取走" + i + " 账上金额为：" + value);
		isMoney = false;
		notifyAll();
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

public class TestCommunicate_2 {
	public static void main(String[] args) {
		Account a1 = new Account();
		new Thread(new Save(a1)).start();
		new Thread(new Save(a1)).start();
		new Thread(new Fetch(a1)).start();
	}
}
