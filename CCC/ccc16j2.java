// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc16j2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
    	int[][] square = new int[4][4];
    	for (int i = 0; i < 4; i++) {
    		for (int j = 0; j < 4; j++) {
    			square[i][j] = readInt();
    		}
    	}
    	boolean flag = true;
    	int sum = square[0][0] + square[0][1] + square[0][2] + square[0][3];
    	for (int i = 0; i < 4; i++) {
    		int tmpsum = 0;
    		for (int j = 0; j < 4; j++) {
    			tmpsum += square[i][j];
    		}
    		if (tmpsum == sum) continue;
    		else {
    			flag = false; break;
    		}
    	}
    	for (int i = 0; i < 4; i++) {
    		int tmpsum = 0;
    		for (int j = 0; j < 4; j++) {
    			tmpsum += square[j][i];
    		}
    		if (tmpsum == sum) continue;
    		else {
    			flag = false; break;
    		}
    	}
    	if (flag) System.out.println("magic");
    	else System.out.println("not magic");
    	
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

}