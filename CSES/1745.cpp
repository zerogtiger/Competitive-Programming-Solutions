#include "iostream"
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> V(N);
    int tot = 0;
    for (auto& i : V) {
        cin >> i;
        tot += i;
    }
    vector<int> dp(tot + 1);
    dp[0] = 1;
    for (int i =0 ; i < N; ++i) {
        for (int j = tot - V[i]; j >= 0; --j) {
            dp[j + V[i]] = max(dp[j + V[i]], dp[j]);
        }
    }
    int ans = 0;
    for (int i =1 ; i <= tot; ++i) {
        if (dp[i] == 1) {
            ++ans;
        }
    }
    cout<< ans << "\n";
    for (int i =1 ; i <= tot; ++i) {
        if (dp[i] == 1) {
            cout<< i << " ";
        }
    }

}
