// Solution by zerogtiger on Github

import java.util.*;
import java.lang.*;
public class ccc15s1 {

	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		Stack<Integer> N = new Stack<Integer>();
		
		int k = s.nextInt();
		
		for (int i = 0; i < k; i ++) {
			int n = s.nextInt();
			if (n == 0) {
				N.pop();
			}else{ 
				N.add(n);
			}
		}
		int sum = 0;
		while(!N.isEmpty()) {
			sum += N.pop();
		}
		System.out.println(sum);

	}

}