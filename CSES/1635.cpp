#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

const int mod = 1e9+7;
int main()
{
    int N;
    int X;
    cin >> N >> X;
    vector<int> V(N);
    for (auto &i : V)
        cin >> i;
    vector<int> dp(X + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= X; ++i) {
        ll ans = 0;
        for (auto & c : V) {
            if (i - c < 0) {
                continue;
            }
            ans = (ans + dp[i - c])%mod;
        }
        dp[i] = ans;
    }
    cout << dp[X] << "\n";

}
