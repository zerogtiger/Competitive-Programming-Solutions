// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc21s1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        int N = readInt();
        int[] H = new int[N+2];
        int[] W = new int[N+1];

        for (int i = 1; i <= N+1; i++) {
            H[i] = readInt();
        }
        for (int i = 1; i <= N; i++) {
            W[i] = readInt();
        }
        double ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += (double) (H[i] + H[i+1])*W[i]/2;
        }
        System.out.printf("%.2f", ans);

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