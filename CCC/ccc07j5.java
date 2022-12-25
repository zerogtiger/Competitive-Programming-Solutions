// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc07j5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        int A = readInt();
        int B = readInt();
        int n = readInt();
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(0);
        temp.add(990);
        temp.add(1010);
        temp.add(1970);
        temp.add(2030);
        temp.add(2940);
        temp.add(3060);
        temp.add(3930);
        temp.add(4060);
        temp.add(4970);
        temp.add(5030);
        temp.add(5990);
        temp.add(6010);
        temp.add(7000);
        for (int i = 1; i <= n; i++) {
            temp.add(readInt());
        }
        Collections.sort(temp);
        int N = temp.size();
        int[] motel = new int[N+1];
        long[] vis = new long[N+1];
        vis[1] = 1;
        for (int i = 1; i <= temp.size(); i++) motel[i] = temp.get(i-1);
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                if (motel[j] >= A + motel[i] && motel[j] <= B + motel[i]) {
                    vis[j] += vis[i];
                }
                if (motel[j] > B + motel[i]) break;
            }
        }
        System.out.println(vis[N]);

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