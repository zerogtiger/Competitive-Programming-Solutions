#include "iostream"
#include <map>
using namespace std;

const int MM = 5005;
int dp[MM][MM];

int main()
{
    string S, T;
    cin >> S >> T;
    int s = S.length();
    int t = T.length();
    for (int i = 0; i <= s; ++i) {
        for (int j = 0; j <= t; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j-1]), dp[i - 1][j - 1]) + 1;
        }
    }
    cout << dp[s][t] << "\n";
}
