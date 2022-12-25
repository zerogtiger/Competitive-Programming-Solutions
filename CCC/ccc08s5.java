// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc08s5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        boolean[][][][] dp = new boolean[31][31][31][31]; //A, B, C, D
        boolean[][][][] U = new boolean[31][31][31][31]; //A, B, C, D

        int N = readInt();

        for (; N > 0; N--) {
            System.out.println(fun(dp, U, readInt(), readInt(), readInt(), readInt()) ? "Patrick" : "Roland");
        }

    }

    static boolean fun(boolean[][][][] dp, boolean[][][][] U, int A, int B, int C, int D) {
        if (U[A][B][C][D])
            return dp[A][B][C][D];
        boolean[] R = reactable(A, B, C, D);
        if (!R[0]) {
            dp[A][B][C][D] = false;
            U[A][B][C][D] = true;
            return false;
        } else {
            int[][] dx = {
                    {2, 1, 0, 2},
                    {1, 1, 1, 1},
                    {0, 0, 2, 1},
                    {0, 3, 0, 0},
                    {1, 0, 0, 1}
            };
            boolean flag = false;
            for (int i = 1; i <= 5; i++) {
                if (R[i])
                    flag = flag || !fun(dp, U, A - dx[i - 1][0], B - dx[i - 1][1], C - dx[i - 1][2], D - dx[i - 1][3]);
            }
            if (flag) {
                dp[A][B][C][D] = true;
                U[A][B][C][D] = true;
                return true;
            } else {
                dp[A][B][C][D] = false;
                U[A][B][C][D] = true;
                return false;
            }
        }
    }

    static boolean[] reactable(int A, int B, int C, int D) {
        boolean[] out = new boolean[6];
        if (A < 0 || B < 0 || C < 0 || D < 0)
            return out;
        if (A > 1 && B > 0 && D > 1)
            out[1] = true;
        if (A > 0 && B > 0 && C > 0 && D > 0)
            out[2] = true;
        if (C > 1 && D > 0)
            out[3] = true;
        if (B > 2)
            out[4] = true;
        if (A > 0 && D > 0)
            out[5] = true;
        out[0] = (out[1] || out[2] || out[3] || out[4] || out[5]);
        return out;
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