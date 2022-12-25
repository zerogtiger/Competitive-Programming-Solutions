// Solution by zerogtiger on Github

import java.util.*;
import java.io.*;

public class ccc22s2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {

        HashMap<String, Integer> conv = new HashMap<>();
        HashMap<Integer, TreeSet<Integer>> toge = new HashMap<>();
        HashMap<Integer, TreeSet<Integer>> away = new HashMap<>();
        int X = readInt();
        for (int i = 1; i <= X; i++) {
            String[] temp = readLine().split(" ");
            if (!conv.containsKey(temp[0])) conv.put(temp[0], conv.size()+1);
            if (!conv.containsKey(temp[1])) conv.put(temp[1], conv.size()+1);
            if (!toge.containsKey(conv.get(temp[0]))) toge.put(conv.get(temp[0]), new TreeSet<>());
            if (!toge.containsKey(conv.get(temp[1]))) toge.put(conv.get(temp[1]), new TreeSet<>());
            toge.get(conv.get(temp[0])).add(conv.get(temp[1]));
            toge.get(conv.get(temp[1])).add(conv.get(temp[0]));
        }
        int Y = readInt();
        for (int i = 1; i <= Y; i++) {
            String[] temp = readLine().split(" ");
            if (!conv.containsKey(temp[0])) conv.put(temp[0], conv.size()+1);
            if (!conv.containsKey(temp[1])) conv.put(temp[1], conv.size()+1);
            if (!away.containsKey(conv.get(temp[0]))) away.put(conv.get(temp[0]), new TreeSet<>());
            if (!away.containsKey(conv.get(temp[1]))) away.put(conv.get(temp[1]), new TreeSet<>());
            away.get(conv.get(temp[0])).add(conv.get(temp[1]));
            away.get(conv.get(temp[1])).add(conv.get(temp[0]));
        }
        int G = readInt();
        int count = 0;
        for (int i = 1; i <= G; i++) {
            String[] temp = readLine().split(" ");
            if (!conv.containsKey(temp[0])) conv.put(temp[0], conv.size()+1);
            if (!conv.containsKey(temp[1])) conv.put(temp[1], conv.size()+1);
            if (!conv.containsKey(temp[2])) conv.put(temp[2], conv.size()+1);
            TreeSet<Integer> group = new TreeSet<>();
            for (int j = 1; j <= 3; j++) {
                int C = conv.get(temp[j-1]);
                group.add(C);
            }
            for (int I: group) {
                if (toge.containsKey(I)) {
                    for (int J: toge.get(I)) {
                        if (!group.contains(J)) count++;
                    }
                }
                if (away.containsKey(I)) {
                    for (int J: away.get(I)) {
                        if (group.contains(J)) count++;
                    }
                }
            }
        }
        System.out.println(count/2);
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