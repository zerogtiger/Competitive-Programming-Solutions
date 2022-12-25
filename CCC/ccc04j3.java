// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc04j3 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int N = s.nextInt();
		int M = s.nextInt();
		s.nextLine();
		String[] adj = new String[N];
		String[] nou = new String[M];
		
		for (int i = 0; i < N; i++) {
			adj[i] = s.nextLine();
		}
		for (int i = 0; i < M; i++) {
			nou[i] = s.nextLine();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.println(adj[i] + " as " + nou[j]);
			}
		}
		

	}

}