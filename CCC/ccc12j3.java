// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc12j3 {

	public static String [][] icon = {
			{"*", "x", "*"},
			{" ", "x", "x"},
			{"*", " ", "*"},
	};
	
	public static Scanner s = new Scanner(System.in);
	
	public static void scaleIcon (String[][] arr, int s) {
		for (int i = 0; i < arr.length; i ++) {
			for (int k = 0; k < s; k ++) {
				for (int j = 0; j < arr[i].length; j ++) {
					for (int h = 0; h < s; h ++) {
						System.out.print(arr[i][j] + "");
					}
				}
				System.out.println();
			}
		}
	}
	
	public static void main(String[] args) {
		
		scaleIcon(icon, s.nextInt());

	}

}