// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class acc5p3 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		String temp = s.nextLine();
		int N = Integer.parseInt(temp.split(" ")[0]);
		int K = Integer.parseInt(temp.split(" ")[1]);
		long sum = 0;
		
		long[] reg = new long[N];
		long[] disc = new long[N];
		long[] diff = new long[N];
		
		for (int i = 0; i < N; i++) {
			temp = s.nextLine();
			reg[i] = Integer.parseInt(temp.split(" ")[0]);
			disc[i] = Integer.parseInt(temp.split(" ")[1]);
			diff[i] = reg[i]-disc[i];
			sum+= reg[i];
		}
		Arrays.sort(diff);
		for (int i = 0; i < K; i++) {
			sum-= diff[N-1-i];
		}
		System.out.println(sum);
	}

}