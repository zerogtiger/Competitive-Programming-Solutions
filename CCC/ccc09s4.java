// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;


public class ccc09s4 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        int N = readInt();
        int T = readInt();

        int[][] adj = new int [N+1][N+1];
        for (int i = 1; i <= N; i++) {
            Arrays.fill(adj[i], 0x7fffffff);
        }
        for (int i = 0; i < T; i++) {
            int X = readInt();
            int Y = readInt();
            int C = readInt();

            adj[X][Y] = C;
            adj[Y][X] = C;
        }
        int K = readInt();
        int[] prices = new int[N+1];
        Arrays.fill(prices, -1);
        for (int i = 0; i < K; i++) {
            int Z = readInt();
            int P = readInt();
            prices[Z] = P;
        }
        int D = readInt();

        //Dijkstra
        long[] dist = new long[N+1];
        Arrays.fill(dist, (int) 1e9);
        boolean[] vis = new boolean[N+1];
        dist[D] = 0;

        for (int i = 1; i <= N; i++) {
            int curr = -1;
            long min = (int) 1e10;
            for (int j = 1; j <= N; j++) {
                if (!vis[j] && dist[j] <= min) {
                    curr = j;
                    min = dist[j];
                }
            }
            if (curr == -1) break;
            vis[curr] = true;
            for (int j = 1; j <= N; j++) {
                if (dist[j] > dist[curr] + adj[curr][j]) {
                    dist[j] = dist[curr] + adj[curr][j];
                }
            }
        }

        long minCost = Long.MAX_VALUE;
        for (int i = 1; i <= N; i++) {
                if (prices[i] > 0 && minCost > prices[i] + dist[i]) {
                    minCost = prices[i] + dist[i];
                }
        }
        System.out.println(minCost);



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