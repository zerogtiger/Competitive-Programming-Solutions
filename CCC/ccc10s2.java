// Solution by zerogtiger on Github

import java.io.*;
import java.util.*;

class branch{
    String leaf;
    branch branch0;
    branch branch1;

    public branch(String leaf) {
        this.leaf = leaf;
    }

    public branch(branch LBranch, branch RBranch) {
        this.branch0 = LBranch;
        this.branch1 = RBranch;
    }

    public void store(String value, String address) {
        if (address.length() == 1) {
            if (address.charAt(0) == '1') branch1 = new branch(value);
            else if (address.charAt(0) == '0') branch0 = new branch(value);
        }else {
            if(address.charAt(0) == '1') {
                if (branch1 == null) branch1 = new branch(null, null);
                branch1.store(value, address.substring(1));
            }
            else if (address.charAt(0) == '0') {
                if (branch0 == null) branch0 = new branch(null, null);
                branch0.store(value, address.substring(1));
            }
        }
    }

    public String access(String address) {
        if (branch1 == null && branch0 == null) {
            System.out.print(leaf);
            return address;
        }else {
            if (address.charAt(0) == '1') return branch1.access(address.substring(1));
            else if (address.charAt(0) == '0') return branch0.access(address.substring(1));
        }
        return null;
    }

    public void print() {
        if (branch0 == null && branch1 == null) {
            System.out.println(leaf);
        }
        if (branch0 == null) {
            System.out.print("null | ");
        }else{
            branch0.print();
        }
        if (branch1 == null) {
            System.out.println("null");
        }else{
            branch1.print();
        }
    }

}

public class ccc10s2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int K = s.nextInt();
        s.nextLine();
        String[] temp;

        branch huffman = new branch(null, null);
        for (int i = 0; i < K; i++) {
            temp = s.nextLine().split(" ");
            huffman.store(temp[0], temp[1]);
        }
        String address = s.nextLine();
        while (address.length() != 0) {
            address = huffman.access(address);
        }
    }
}
