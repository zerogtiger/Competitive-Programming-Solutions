#include "iostream"
using namespace std;

int dp[505][505];

int main()
{
    int A, B;
    cin >> A >> B;
    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                int mn = 0x3f3f3f3f;
                for (int k = 1; k < i; ++k) {
                    mn = min(mn, dp[i - k][j] + dp[k][j] + 1);
                }
                for (int k = 1; k < j; ++k) {
                    mn = min(mn, dp[i][j - k] + dp[i][k] + 1);
                }
                dp[i][j] = mn;
            }
        }
    }
    cout << dp[A][B] << "\n";
}
