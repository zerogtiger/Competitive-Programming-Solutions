// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc13j4 {

	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {

		int T = s.nextInt();
		int C = s.nextInt();
		
		int tmetkn = 0;
		int numOfChr = 0;
		int[] chrtme = new int[C];
		
		for (int i = 0; i < C; i++) {
			chrtme[i] = s.nextInt();
		}
		Arrays.sort(chrtme);
		for (int i = 0; i < C; i++) {
			tmetkn += chrtme[i];
			numOfChr ++;
			if (tmetkn > T) {
				numOfChr--;
				break;
			}
		}
		System.out.println(numOfChr);
	}

}