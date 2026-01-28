#include "iostream"
#include "set"
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    int X, N;
    cin >> X >> N;
    set<int> st;
    vector<int> V;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        st.insert(a);
        V.push_back(a);
    }
    int ans = 0;
    st.insert(0);
    st.insert(X);
    for (auto& i : st) {
        if (i == X) {
            continue;
        }
        auto nxt = st.upper_bound(i);
        ans = max(ans, *nxt - i);
    }
    vector<int> out;
    out.push_back(ans);
    while (N--, N) {
        int i = V[N];
        if (i == 0 || i == X) {
            out.push_back(ans);
            continue;
        }
        else {
            st.erase(i);
            auto res = st.upper_bound(i);
            // cout << *res << " " << *prev(res) << "\n";
            ans = max(ans, *res - *prev(res));
        }
        out.push_back(ans);
    }
    reverse(out.begin(), out.end());
    for (auto &i : out) {
        cout << i << " ";
    }
}
