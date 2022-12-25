// Solution by zerogtiger on Github

import java.lang.*;
import java.util.*;

public class ccc09j3 {

	public static String timeKeeper(int H, int M, int A) {
		int[] time = new int[2];
		time[0] = ((H + ((M+A)/60))%24);
		time[1] = ((M+A%60)%60);
		String ans = "";
		if (time[0] != 0) {
			ans+= Integer.toString(time[0]);
		}
		if (time[1] < 10 && time[0] != 0) {
			ans+=("0" + Integer.toString(time[1]));
		}else {
			ans += Integer.toString(time[1]);
		}
		return ans;
	}
	
	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		Integer T = (s.nextInt() + 10000);
		String time = Integer.toString(T);
		int H = Integer.parseInt(time.substring(1, 3));
		int M = Integer.parseInt(time.substring(3, 5));
		
		System.out.println((timeKeeper(H, M, 0)) + " in Ottawa");
		System.out.println((timeKeeper(H, M, 1260)) + " in Victoria");
		System.out.println((timeKeeper(H, M, 1320)) + " in Edmonton");
		System.out.println((timeKeeper(H, M, 1380)) + " in Winnipeg");
		System.out.println((timeKeeper(H, M, 0)) + " in Toronto");
		System.out.println((timeKeeper(H, M, 60)) + " in Halifax");
		System.out.println((timeKeeper(H, M, 90)) + " in St. John\'s");
	}

}