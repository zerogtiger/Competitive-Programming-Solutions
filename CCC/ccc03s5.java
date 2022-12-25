// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;
public class ccc03s5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int c = readInt();
        int r = readInt();
        int d = readInt();
        List<Pair> adj[] = new List[c+1];
        for (int i = 1; i <= c; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 1; i <= r; i++) {
            int u = readInt();
            int v = readInt();
            int w = readInt();
            adj[u].add(new Pair(v, w));
            adj[v].add(new Pair(u, w));
        }

        int[] min = new int[c+1];
        boolean[] vis = new boolean[c+1];
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(1, 0x3f3f3f3f));
        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            if (vis[curr.v]) continue;
            vis[curr.v] = true;
            for (Pair p: adj[curr.v]) {
                if (Math.min(curr.w, p.w) > min[p.v]) {
                    min[p.v] = Math.min(curr.w, p.w);
                    pq.add(new Pair(p.v, min[p.v]));
                }
            }
        }
        int minW = 0x3f3f3f3f;
        for (int i = 1; i <= d; i++) {
            int dest = readInt();
            minW = Math.min(minW, min[dest]);
        }
        System.out.println(minW);
    }

    private static class Pair implements Comparable<Pair>{
        int v;
        int w;

        public Pair (int v0, int w0) {
            v = v0;
            w = w0;
        }

        @Override
        public String toString() {
            return ("(" + v + ", " + w + ")");
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(-w, -other.w);
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