// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class aac6p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        long N = readInt();
        long I = readInt();

        for (int i = 1; i < N; i++) {
            System.out.print(i + " ");
        }
        long M = ((N)*(N+1)/2)%I;

        System.out.println(N + (I-M));
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