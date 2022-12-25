// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class aac5p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        long N = readInt();
        long[] ini = new long[4];
        long[] per = new long[(int) N+1];
        long tot = N * (N + 1) /2;
        System.out.println("? 1 2");
        System.out.flush();
        ini[1] = readLong();
        System.out.println("? 2 3");
        System.out.flush();
        ini[2] = readLong();
        if (N == 3) {
            ini[3] = 11 - ini[1] - ini[2];
        }
        else {
            System.out.println("? 3 1");
            System.out.flush();
            ini[3] = readLong();
        }
        per[1] = (long) Math.sqrt((((double)ini[1])*((double)ini[3]))/(double)ini[2]);
        per[2] = ini[1]/per[1];
        per[3] = ini[3]/per[1];
        for (int i = 1; i <= 3; i++) {
            tot -= per[i];
        }
        for (long i = 4; i < N; i++) {
            System.out.println("? 1 " + i);
            System.out.flush();
            long A = readLong();
            per[(int)i] = A/per[1];
            tot -= per[(int)i];
        }
        System.out.print("! ");
        for (long i = 1; i < N; i++) {
            System.out.print(per[(int)i] + " ");
        }
        System.out.println(N == 3? per[(int) N]: tot);
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