// Solution by zerogtiger on Github

import java.util.*;

class pair {
    String s;
    Integer n;

    public pair(String s, Integer n) {
        this.s = s;
        this.n = n;
    }
}

public class ccc10s1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        s.nextLine();
        TreeMap<String, Integer> comp = new TreeMap<>();
        String[] temp;
        for (int i = 0; i < N; i++) {
            temp = s.nextLine().split(" ");
            comp.put(temp[0], (Integer.parseInt(temp[1])*2+Integer.parseInt(temp[2])*3+Integer.parseInt(temp[3])));
        }

        pair fir = new pair("", 0);
        pair sec = new pair("", 0);

        for (String S: comp.keySet()) {
            if (comp.get(S) > fir.n) {
                sec.s = fir.s;
                sec.n = fir.n;
                fir.s = S;
                fir.n = comp.get(S);
            }
            else if (comp.get(S) > sec.n) {
                sec.s = S;
                sec.n = comp.get(S);
            }
            else if (comp.get(S) == fir.n && sec.s.equals("")) {
                sec.s = S;
                sec.n = comp.get(S);
            }

        }
        System.out.println(fir.s);
        if (!sec.s.equals("")) System.out.println(sec.s);
    }
}