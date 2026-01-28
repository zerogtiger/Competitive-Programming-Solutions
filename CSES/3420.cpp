#include "iostream"
#include <set>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

const int MM = 2e5 + 7;
int V[MM], nxt[MM];

ll fun(int lft, int rht) { // inclusive, exclusive
    if (rht ==lft) {
        return 0;
    }
    else if (rht - lft == 1) {
        return 1;
    }
    else if (rht - lft == 2) {
        if (V[lft] == V[rht - 1])
            return 2;
        else
            return 3;
    }
    else {
        ll mid = (lft + rht) / 2;
        ll ans = fun(lft, mid) + fun(mid, rht);
        set<int> st;
        int rlim = mid;
        for (; rlim < rht && !st.count(V[rlim]); ++rlim) {
            st.insert(V[rlim]);
        }
        st.clear();
        int llim = mid;
        for (; llim >= lft && !st.count(V[llim]); --llim) {
            st.insert(V[llim]);
        }
        llim++;
        for (int i = mid - 1; i >= llim; --i) {
            if (nxt[i] <= mid) 
                continue;
            ll aha = min(rlim, nxt[i]);
            ans += (aha - mid);
            rlim = min(rlim, nxt[i]);
        }
        return ans;
    }
}

int main() {
    int N;
    cin >> N;
    map<int, int> prev; // last seen index
    for (int i =1; i <= N; ++i) {
        cin >> V[i];
        if (prev[V[i]] != 0) {
            nxt[prev[V[i]]] = i;
        }
        prev[V[i]] = i;
    }
    for (int i =1; i <= N; ++i) {
        if (nxt[i] == 0)
            nxt[i] = N + 1;
    }
    cout << fun(1, N + 1) << "\n";

}
