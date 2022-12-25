// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;
public class ccc04s5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int M = readInt();
        int N = readInt();

        while (M > 0 && N > 0) {
            int[][][] dp = new int[M+2][N+2][2];
            char[][] G = new char[M+2][N+2];
            for (int i = 1; i <= M; i++) {
                G[i] = (" " + readLine() + " ").toCharArray();
                for (int j = 1; j <= N; j++) {
                    Arrays.fill(dp[i][j], (int) -1e9);
                }
            }

            for (int i = M; i > 0; i--) {
                if (G[i][1] == '.')
                    dp[i][1][1] = dp[i+1][1][1];
                else if (G[i][1] == '*')
                    dp[i][1][1] = (int) -1e9;
                else
                    dp[i][1][1] = dp[i+1][1][1] + Integer.parseInt("" + G[i][1]);
            }

            for (int i = 2; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (G[j][i] == '.')
                        dp[j][i][0] = Math.max(dp[j][i-1][0], Math.max(dp[j][i-1][1], dp[j-1][i][0]));
                    else if (G[j][i] == '*')
                        dp[j][i][0] = (int) -1e9;
                    else {
                        dp[j][i][0] = Math.max(dp[j][i-1][0], Math.max(dp[j][i-1][1], dp[j-1][i][0])) + Integer.parseInt("" + G[j][i]);
                    }
                }
                for (int j = M; j > 0; j--) {
                    if (G[j][i] == '.')
                        dp[j][i][1] = Math.max(dp[j][i-1][1], Math.max(dp[j][i-1][0], dp[j+1][i][1]));
                    else if (G[j][i] == '*')
                        dp[j][i][1] = (int) -1e9;
                    else {
                        dp[j][i][1] = Math.max(dp[j][i-1][1], Math.max(dp[j][i-1][0], dp[j+1][i][1])) + Integer.parseInt("" + G[j][i]);
                    }
                }
            }
            System.out.println(Math.max(dp[M][N][1], dp[M][N][0]));
            M = readInt();
            N = readInt();
        }
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