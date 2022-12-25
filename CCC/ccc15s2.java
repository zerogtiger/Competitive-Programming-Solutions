// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc15s2 {

	public static Scanner s = new Scanner(System.in);
	
	//translate jersey size into integer
	public static int intoSize(String s) {
		int size = 0;
		if (s.equals("S")) {
			size = 1;
		}else if (s.equals("M")){
			size = 2;
		}else if (s.equals("L")){
			size = 3;
		}
		return size;
	}
	
	//put all available jersey into an organized array
	public static int[] intoArray(int num) {
		int[] jersey = new int[num];
		for (int i = 0; i < num; i ++) {
			jersey[i] = intoSize(s.nextLine());
		}
		return jersey;
	}
	
	//Check if the available jersey is the same or larger than
	//the requested size. 
	public static int fit(int[] jersey, String s, int num) {
		int bool = 0;
		if (jersey[num-1] >= intoSize(s)) {
			bool = 1;
		}
		return bool;
	}
	
	//Driver Code
	public static void main(String[] args) {
	
		String momentary = "";
		String size = "";
		int num = 0;
		int sum = 0;
		
		int totalJersey = s.nextInt();
		s.nextLine();
		int requests = s.nextInt();
		s.nextLine();
		
		int[] jersey = new int[totalJersey];
		
		jersey = intoArray(totalJersey);
		
		for (int i = 0; i < requests; i ++) {
			momentary = s.nextLine();
			size = momentary.substring(0, 1);
			num = Integer.parseInt(momentary.substring(2));
			sum += (fit(jersey, size, num));
			
			if (fit(jersey, size, num) == 1) {
				jersey[num-1] = 0;
			}
		}
		
		System.out.println(sum);
	
	}

}