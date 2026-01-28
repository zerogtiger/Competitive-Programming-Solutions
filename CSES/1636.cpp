#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7, inf = 1e6 + 7;
ll dp[inf];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X;
    cin >> N >> X;
    vector<int> V(N);
    for (auto& i : V) {
        cin >> i;
    }
    for (int i = 0; i <= N; ++i) {
        dp[0] = 1;
    }
    for (int j = 0; j < N; ++j) {
        for (int i = V[j]; i <= X; ++i) {
            dp[i] = (dp[i] + dp[i - V[j]])%mod;
        }
    }
    cout << dp[X] << "\n";
}
