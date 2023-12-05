package uva272;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		 Scanner scanner = new Scanner(System.in);
		 boolean second = false;
		 while(scanner.hasNext()) {
			 String inputLine = scanner.nextLine();
			 inputLine = inputLine + "\247";
			 String[] quotes = inputLine.split("\"");
			 String newstring = "";
			 int i = 1;
			 for(String s : quotes) {
				 if(i != quotes.length || inputLine.endsWith("\"")) {
					 if(!second) {
						 s = s + "``";
						 second = true;
					 } else {
						 s = s + "''";
						 second = false;
					 }
				 }
				 newstring = newstring + s.replaceAll("\247", "");
				 i++;
			 }
			 
			 System.out.println(newstring);
		 }
		 scanner.close();

	}
}