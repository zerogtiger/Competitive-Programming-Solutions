// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc11j2 {

	public static Scanner s = new Scanner(System.in);
	
	public static int function (int t, int h) {
		int A;
		A = -6*(t*t*t*t) + h*t*t*t + 2*t*t + t;
		return (A);
	}
	
	public static int touchGround (int h, int m) {
		int A = 0;
		int t = 1;
		do {
			if (function(t,h) <=0) {
				break;
			}
			t ++;
		} while(t < m);
		return t;
	}
	
	public static void main(String[] args) {
		
		int h = s.nextInt();
		int m = s.nextInt();
		int t = touchGround(h, m);
		
		if (t == m) {
			System.out.println("The balloon does not touch ground in the given time.");
		}
		else if (t <= m) {
			System.out.println("The balloon first touches ground at hour: \n" + t);
		}
	
	}

}