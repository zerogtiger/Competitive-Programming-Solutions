// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc10j2 {

	public static Scanner s = new Scanner(System.in);
	
	public static int distanceCalc(int a, int b, int s) {
		int distance = 0;
		int steps = 0;
		do {
			for (int i = 0; i < a; i ++) {
				if (steps > s) {
					break;
				}
				distance ++;
				steps ++;
			}
			for (int i = 0; i < b; i ++) {
				if (steps > s) {
					break;
				}
				distance --;
				steps ++;
			}
		} while(steps <=s);
		return distance;
	}
	
	public static void main(String[] args) {
		
		int a, b, c, d, y, n, g;
		a = s.nextInt();
		b = s.nextInt();
		c = s.nextInt();
		d = s.nextInt();
		g = s.nextInt();
		
		n = distanceCalc(a, b, g);
		y = distanceCalc(c, d, g);

		if (y > n) {
			System.out.println("Byron");
		}else if (y < n) {
			System.out.println("Nikky");
		}else {
			System.out.println("Tied");
		}
	}
}