#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

int dp[1005][1005];
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1), B(M + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= M; ++i) {
        cin >> B[i];
    }
    for (int n = 0; n <= N; ++n) {
        for (int m = 0; m <= M; ++m) {
            if (n == 0 || m == 0)
                dp[n][m] = 0;
            else if (A[n] == B[m]) {
                dp[n][m] = dp[n - 1][m - 1] + 1;
            }
            else
                dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
        }
    }
    cout << dp[N][M] << "\n";
    int n = N, m = M;
    vector<int> ans;
    while (n > 0 && m > 0) {
        if (A[n] == B[m]) {
            ans.push_back(A[n]);
            n -= 1;
            m -= 1;
        }
        else if (dp[n][m] == dp[n - 1][m])
            n -= 1;
        else
            m -= 1;
    }
    reverse(ans.begin(), ans.end());
    for (auto &i : ans)
        cout << i << " ";
}
