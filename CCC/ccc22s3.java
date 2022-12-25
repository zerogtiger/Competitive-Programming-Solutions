// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc22s3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        long N = readInt();
        long M = readInt();
        long K = readLong();
        long KMax = Math.max(0, (N-M)*M) + (Math.min(N, M)) * (Math.min(N, M)+1)/2;
        if (K > KMax || K < N) System.out.println(-1);
        else {
            int L = 1;
            int[] P = new int[(int) (N+1)];
            Arrays.fill(P, -1);
            K -= N;
            P[1] = 0;
            for (int i = 1; i <= Math.min(N, M); i++) {
                if (K >= i-1) {
                    P[i] = i;
                    L = i;
                    K -= (i-1);
                }else {
                    P[i] = P[(int) (i-K-1)];
                    L = P[i];
                    K = 0;
                    break;
                }
            }
            for (int i = (int) (Math.min(N, M)+1); i <= N; i++) {
                if (K == 0)
                    break;
                else if (K >= M) {
                    P[i] = (int) ((P[i-1]) % M + 1);
                    L = P[i];
                    K -= M-1;
                }else {
                    P[i] = P[(int) (i-K-1)];
                    L = P[i];
                    break;
                }
            }
            System.out.print(P[1]);
            for (int i = 2; i <= N; i++) {
                System.out.print(P[i] == -1? " " + L: " " + P[i]);
            }
            System.out.println();

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