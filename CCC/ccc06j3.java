// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc06j3 {

	public static int time(String s) {
		String[][] button = new String[8][4];
		button[0][0] = "a";
		button[0][1] = "b";
		button[0][2] = "c";
		button[0][3] = "";
		button[1][0] = "d";
		button[1][1] = "e";
		button[1][2] = "f";
		button[1][3] = "";
		button[2][0] = "g";
		button[2][1] = "h";
		button[2][2] = "i";
		button[2][3] = "";
		button[3][0] = "j";
		button[3][1] = "k";
		button[3][2] = "l";
		button[3][3] = "";
		button[4][0] = "m";
		button[4][1] = "n";
		button[4][2] = "o";
		button[4][3] = "";
		button[5][0] = "p";
		button[5][1] = "q";
		button[5][2] = "r";
		button[5][3] = "s";
		button[6][0] = "t";
		button[6][1] = "u";
		button[6][2] = "v";
		button[6][3] = "";
		button[7][0] = "w";
		button[7][1] = "x";
		button[7][2] = "y";
		button[7][3] = "z";
		
		int time = 0;
		int num = -1;
		
		for(int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 8; j++) {
 				for (int h = 0; h < 4; h++) {
 					if(button[j][h].equals(s.substring(i, i+1))) {
 						time += h+1;
 						if(j == num) {
 							time += 2;
 						}
 						num = j;
 					}
 				}
			}
		}
		return time;

	}
	
	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		String S = s.nextLine();
		while (!S.equals("halt")) {
			System.out.println(time(S));
			S = s.nextLine();
		}
		
		
		
	}

}