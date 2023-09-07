import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int zerosInARow = 0;
		String lineBuilder = "";
		while(zerosInARow < 3) {
			int num = scan.nextInt();
			if(num != 0)
				lineBuilder = lineBuilder + num + " ";
			else if(lineBuilder.length() == 0)
				zerosInARow++;
			
			if(num == 0 && lineBuilder.length() > 0) {
				List<Light> lights = new ArrayList<>();
				String[] line = lineBuilder.trim().split(" ");
				for(String s : line) {
					Light l = new Main().new Light(Integer.valueOf(s));
					lights.add(l);
				}
				simulateLights(lights);
				lineBuilder = "";
				continue;
			}
		}
		scan.close(); 
	}
	
	public static void simulateLights(List<Light> lights) {
		int time = 18000;
		boolean initState = true;
		boolean loopDone = false;
		for(int i = 0; i <= time; i++) {
			boolean anyRed = false;
			for(Light x : lights) {
				if(x.getIsRedOrOrange()) {
					anyRed = true;
					initState = false;
				}
			}
			if(!initState && !anyRed) {
				int hours = i / 3600;
				int minutes = (i % 3600) / 60;
				int seconds = i % 60;

				String t = String.format("%02d:%02d:%02d", hours, minutes, seconds);
				System.out.println(t.trim());
				loopDone = true;
				break;
			}
			for(Light x : lights) {
				x.simulate();		
			}
		if(loopDone)
			break;	
		} else
			System.out.println("Signals fail to synchronise in 5 hours");
	}
	
	public class Light {
		
		private int cycleTime;
		private int currentTime;
		private boolean isRedOrOrange;
		
		public Light(int cycleTime) {
			this.cycleTime = cycleTime;
			this.currentTime = cycleTime;
		}
		
		public void simulate(Integer... timeAdvance) {
			Integer advanceTime;
			if (timeAdvance.length == 1) {
				advanceTime = timeAdvance[0];
			} else {
				advanceTime = 1;
			}
			
			currentTime -= advanceTime;
			if(currentTime <= 5) {
				isRedOrOrange = true;
				if(currentTime <= -cycleTime) {
					isRedOrOrange = false;
					currentTime = cycleTime;
				}
			}
		}
	}
}
