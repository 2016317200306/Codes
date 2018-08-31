package admin;

class FighterPlane {
	String name;
	int missileNum;
	void fire() {
		if(missileNum > 0) {
			System.out.println("now fire a missile!");
			missileNum--;
		}
		else {
			System.out.println("No missile left!");
		}
	}
}

public class RunPlane {
	public static void main(String[] args) {
		FighterPlane fp = new FighterPlane();
		fp.name = "su35";
		fp.missileNum = 6;
		fp.fire();

	}

}
