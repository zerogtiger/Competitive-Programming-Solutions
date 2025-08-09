#include "iostream"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<int> V(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> V[i];
    sort(V.begin(), V.end());
    vector<int> dp(N + 1, 0);
    // for (auto &i : V) {
    //     cout << i << " ";
    // }
    int ans = 0;
    for (int l = 1, r = 1; r <= N; ++r) {
        while (V[r] - V[l] > K) {
            ++l;
        }
        dp[r] = max(dp[r - 1], r - l + 1);
        ans = max(ans, r - l + 1 + dp[l - 1]);
    }
    cout << ans << "\n";
}
