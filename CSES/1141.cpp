#include "iostream"
#include "set"
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> st;
    vector<int> V(N);
    for (auto &i : V)
        cin >> i;
    int ans = 0;
    for (int l = 0, r = 0; r < N; ++r) {
        while (st.count(V[r])) {
            st.erase(V[l++]);
        }
        st.insert(V[r]);
        ans = max(ans, (int) st.size());
    }
    cout << ans << "\n";
}
