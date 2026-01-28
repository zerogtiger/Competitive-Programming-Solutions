#include "iostream"
using namespace std;

typedef long long ll;
const int MM = 500 * 250 + 4, mod = 1e9 + 7;
ll dp[505][MM];
int main()
{
    int N;
    cin >> N;
    int m = N * (N + 1) / 2;
    if (m % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    m /= 2;
    for (int i = 0; i <= m; ++i) {
        for (int k = 1; k <= N; ++k) {
            if (i == 0)
                dp[k][i] = 1;
            else
                dp[k][i] = (dp[k - 1][i] + (i - k >= 0 ? dp[k - 1][i - k] : 0)) % mod;
        }
    }
    cout << dp[N][m] << "\n";
}
