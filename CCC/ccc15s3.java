// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc15s3 {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		int G = s.nextInt();
		int P = s.nextInt();
		
		TreeSet<Integer> docks = new TreeSet<Integer>();
		
		for (int i = 0; i < G; i++) {
			docks.add(i+1);
		}
		
		for (int i = 0; i < P; i ++) {
			int D = s.nextInt();
			if (docks.floor(D) == null) {
				System.out.println(i);
				System.exit(0);
			}else {
				docks.remove(docks.floor(D));
			}
		}
		System.out.println(P);
	}

}