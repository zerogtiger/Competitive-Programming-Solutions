#include "iostream"
using namespace std;

const int inf = 1e6 + 8, mod = 1e9 + 7;
long long dp[inf][2]; // together, divided
int main()
{
    int T;
    cin >> T;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        dp[i][0] = (dp[i - 1][1] + 2 * dp[i - 1][0]) % mod;
        dp[i][1] = ((4 * dp[i - 1][1]) + dp[i - 1][0]) % mod;
    }
    while (T--) {
        int i;
        cin >> i;
        cout << (dp[i][0] + dp[i][1]) % mod << "\n";
    }
}
