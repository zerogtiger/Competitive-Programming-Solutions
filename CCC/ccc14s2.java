// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc14s2 {

	public static Scanner s = new Scanner(System.in);
	
	public static Integer search(String[] name, String N) {
		Integer ans = 0;
		for (int i = 0; i < name.length; i ++) {
			if (name[i].equals(N)) {
				ans = i;
			}
		}
		return ans;
	}
	
	public static String[] IA(int S) {
		String[] student = new String[S];
		String temp = s.nextLine();
		student = temp.split(" ");
		return student;
	}
	
	public static void main(String[] args) {
		
		int S = s.nextInt();
		s.nextLine();
		String[] name1 = IA(S);
		String[] name2 = IA(S);
		String[][] names = {name1, name2};

		String ans = "good";
		
		for (int i = 0; i < S; i++) {
			if (name1[i].equals(name2[i])) {
				ans = "bad";
				break;
			}
		}
		
		for (int i = 0; i < S; i++) {
			int index = 0;
			index = search(name2, name1[i]);
			if(!name2[i].equals(name1[index])) {
				ans = "bad";
			}
		}
		
		System.out.println(ans);
	}

}