// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;
public class ccc00s1 {

	public static int calc(int Q, int A, int B, int C) {
		if(Q <= 0) {
			return Q;
		}else {
			A += (Q/3);
			B += (Q/3);
			C += (Q/3);
			int N = 0;
			if(Q%3 == 1) {
				A+=1;
			}
			if(Q%3 == 2) {
				B+=1;
			}
			N+= (A/35)*30;
			N+= (B/100)*60;
			N+= (C/10)*9;
			return Q+calc(N, A%35, B%100, C%10);
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int Q = s.nextInt();
		int[] slot = new int[3];
		for (int i = 0; i < 3; i++) {
			slot[i] = s.nextInt();
		}
		System.out.println("Martha plays "+ calc(Q, slot[0], slot[1], slot[2]) + " times before going broke.");
	}
}