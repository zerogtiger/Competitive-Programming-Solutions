// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc14s3 {

	public static Scanner s = new Scanner(System.in);
	
	public static Stack<Integer> intoStack(int length) {
		Stack<Integer> top = new Stack<Integer>();
		top.push(0);
		for (int i = 0; i < length; i ++) {
			top.push(s.nextInt());
		}
		return top;
	}
	
	public static boolean isIngredient(Stack<Integer> top) {
		boolean isOrdered = true;
		Stack<Integer> branch = new Stack<Integer>();
		branch.push(0);
		int cart = 1;
		while ((top.peek() != 0 || branch.peek() != 0)) {
			if (top.peek() == cart) {
				top.pop();
				cart++;
			} else if(branch.peek() == cart) {
				branch.pop();
				cart++;
			} else if (top.peek() != 0) {
				branch.push(top.peek());
				top.pop();
			} else {
				isOrdered = false;
				break;
			}
		}
		return isOrdered;
	}
	
	public static void main(String[] args) {
		int cases = s.nextInt();
		
		boolean[] result = new boolean[cases];
		Stack<Integer> top;
		
		String yum = "";
		
		for (int i = 0; i < cases; i ++) {
			int length = s.nextInt();
			top = intoStack(length);
			result[i] = isIngredient(top);
		}
		
		for (int i = 0; i < cases; i ++) {
			if (result[i] == true) {
				yum = "Y";
			}else {
				yum = "N";
			}
			System.out.println(yum);
		}
	}
}