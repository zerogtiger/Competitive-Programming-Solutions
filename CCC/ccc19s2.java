// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc19s2 {

	public static boolean isPrime(int N) {
		boolean isPrime = true;
		if(N %2 == 0) {
			isPrime = false;
		}else {
			for (int i = 3; i*i <= N; i+=2) {
				if(N%i == 0) {
					isPrime = false;
					break;
				}
			}
		}
		return isPrime;
	}
	
	public static String averagePrime(int N) {
		int[] ans = new int[2];
		N = N*2;
		for (int i = 3; i <=N; i+=2) {
			if (isPrime(i) && isPrime(N-i)) {
				ans[0] = i;
				ans[1] = (N-i);
				break;
			}
		}
		return(ans[0] + " " + ans[1]);
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		String[] out = new String[T];
		for (int i = 0; i < T; i++) {
			out[i] = averagePrime(s.nextInt());
		}
		for (String value: out) {
			System.out.println(value);
		}

	}

}