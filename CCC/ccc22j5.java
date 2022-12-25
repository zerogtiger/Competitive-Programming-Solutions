// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc22j5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

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
            return Integer.compare(w, other.w);
        }
    }

    public static void main(String[] args) throws IOException {
        int N = readInt();
        int T = readInt();
        ArrayList<Pair> trees = new ArrayList<>();
        trees.add(new Pair(0, 0));
        trees.add(new Pair(N+1, N+1));
        for (int i = 1; i <= T; i++) {
            trees.add(new Pair(readInt(), readInt()));
        }
        Collections.sort(trees);

        int max = -1;
        ArrayList<Integer> inMiddle = new ArrayList<>();
        for (int l = 0; l < trees.size(); l++) {
            for (int u = l + 1; u < trees.size(); u++) {
                inMiddle.add(0);
                inMiddle.add(N+1);
                for (int i = l+1; i < u; i++) {
                    inMiddle.add(trees.get(i).v);
                }
                Collections.sort(inMiddle);
                for (int i = 1; i < inMiddle.size(); i++) {
                    max = Math.max(max, Math.min(trees.get(u).w - trees.get(l).w-1, inMiddle.get(i) - inMiddle.get(i-1) -1));
                }
                inMiddle.clear();
            }
        }
        System.out.println(max);

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