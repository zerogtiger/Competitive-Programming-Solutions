// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc21s2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        int M = readInt();
        int N = readInt();
        int[] R = new int[M+1];
        int[] C = new int[N+1];
        int K = readInt();
        for (int i = 1; i <= K; i++) {
            String[] temp = readLine().split(" ");
            if (temp[0].equals("R")) R[Integer.parseInt(temp[1])] = 1 - R[Integer.parseInt(temp[1])];
            else if (temp[0].equals("C")) C[Integer.parseInt(temp[1])] = 1 - C[Integer.parseInt(temp[1])];
        }
        int Rsum = 0, Csum = 0;
        for (int i = 1; i <= M; i++) {
            Rsum += R[i];
        }
        for (int i = 1; i <= N; i++) {
            Csum += C[i];
        }
        System.out.println((Rsum * (N - Csum)) + (Csum * (M - Rsum)));

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