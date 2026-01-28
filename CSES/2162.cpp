#include "iostream"
#include <cmath>
using namespace std;

const int MM = 1e6;
int t[MM];
int ceiled, N;

void build(int lft, int rht, int idx)
{ // inclusive, exclusive
    if (rht - lft == 1 && lft <= N)
        t[idx] = 1;
    else if (rht - lft == 1)
        t[idx] = 0;
    else {
        build(lft, (rht + lft) / 2, idx * 2);
        build((rht + lft) / 2, rht, idx * 2 + 1);
        t[idx] = t[2 * idx] + t[2 * idx + 1];
    }
}

int sch(int val, int lft, int rht, int idx) {
    t[idx]--;
    if (rht - lft == 1) {
        return lft;
    }
    if (t[2*idx] >= val)
        return sch(val, lft, (rht + lft)/2, 2*idx);
    return sch(val - t[2*idx], (rht + lft)/2, rht, 2*idx + 1);
}

int main()
{
    int K = 1;
    cin >> N;
    ceiled = (1 << (int) ceil(log2(N)));
    build(1, ceiled + 1, 1);
    int cnt = N;
    int prev = 1;
    while (cnt > 0) {
        int nxt = (prev + K - 1) % cnt + 1;
        cout << sch(nxt, 1, ceiled + 1, 1) << " "; // returns element, decrements along path
        cnt--;
        prev = nxt;
    }
}

