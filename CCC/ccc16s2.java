// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc16s2 {

	public static Scanner s = new Scanner(System.in);
	
	public static int[] intoArray(int[] cntst) {
		String[] temp;
		temp = s.nextLine().split(" ");
		
		for (int i = 0; i < temp.length; i ++) {
			cntst[i] = Integer.parseInt(temp[i]);
		}
		Arrays.sort(cntst);
		return cntst;
	}
	
	public static void main(String[] args) {
		
		int Q = s.nextInt();
		int N = s.nextInt();
		int spd = 0;
		
		int[] D = new int[N];
		int[] P = new int[N];
		
		s.nextLine();
		intoArray(D);
		intoArray(P);
		
		if (Q == 1) {
			for (int i = 0; i < N; i++) {
				spd += Math.max(D[i], P[i]);
			}
		} else {
			for (int i = 0; i < N; i++) {
				spd += Math.max(D[i], P[N-i-1]);
			}
		}		
		System.out.println(spd);
	}

}