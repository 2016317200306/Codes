package admin;

public class FighterPlane {
	String name;
	int missileNum;
	void fire() {
		if(missileNum > 0) {
			missileNum--;
			System.out.println("Now fire a missile!");
		}
		else {
			System.out.println("No missile left!");
		}
	}
}
