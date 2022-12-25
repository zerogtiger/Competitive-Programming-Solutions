// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class aac5p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        int N = readInt();
        int[] batches = new int[3];

        for (int i = 1; i <= N; i++) {
           int B = readInt();
           if (B%2 == 1) batches[1]++;
           else batches[2]++;
        }
        System.out.println((batches[1]/2 + batches[2]/2));
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