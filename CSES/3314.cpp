#include "iostream"
#include "algorithm"
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N + 1);
    vector<pair<int, int>> V(N + 1);
    int mn = 0x3f3f3f3f;
    for (int i = 1; i <= N; ++i) {
        int h;
        cin >> h;
        V[i] = {h, i};
        mn = min(mn, h);
    }
    vector<int> lft(N + 1), rht(N + 1);
    vector<pair<int, int>> st;
    st.push_back({0x3f3f3f3f, 0});
    for (int i = 1; i <= N; ++i) {
        while (st.back().first <= V[i].first)
            st.pop_back();
        lft[i] = st.back().second;
        st.push_back(V[i]);
    }
    st.clear();
    st.push_back({0x3f3f3f3f, N + 1});
    for (int i = N; i > 0; --i) {
        while (st.back().first <= V[i].first)
            st.pop_back();
        rht[i] = st.back().second;
        st.push_back(V[i]);
    }
    // for (auto& i : lft) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for (auto& i : rht) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    sort(V.begin(), V.end());
    for (int i = 1; i <= N; ++i) {
        auto p = V[i];
        dp[p.second] = max(dp[p.second], 1);
        dp[lft[p.second]] = max(dp[lft[p.second]], dp[p.second] + 1);
        dp[rht[p.second]] = max(dp[rht[p.second]], dp[p.second] + 1);
    }
    int mx = 0;
    for (int i =1; i <= N; ++i) {
        // cout << dp[i] << " ";
        mx = max(mx, dp[i]);
    }
    // cout<< "\n";
    cout<< mx << "\n";
    
    
}
