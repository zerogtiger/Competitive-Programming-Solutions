#include "iostream"
using namespace std;

const int MM = 1007, mod = 1e9+7;
int dp[MM][MM];
bool V[MM][MM];

int main()
{
    int N; cin >> N;
    for (int i = 0; i <= N + 1; ++i) {
        for (int j = 0; j <= N + 1; ++j) {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
                V[i][j] = true;
                continue;
            }
            char tmp;
            cin >> tmp;
            V[i][j] = tmp == '*';
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == 1 && j == 1 && !V[i][j])
                dp[i][j] = 1;
            else if (!V[i][j]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%mod;
            }
        }
    }
    cout << dp[N][N] << "\n";
}
