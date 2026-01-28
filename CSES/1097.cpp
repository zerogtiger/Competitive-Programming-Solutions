#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

const int MM = 5005;
ll dp[MM][MM];

int main()
{
    int N;
    cin >> N;
    vector<ll> V(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
        V[i] += V[i - 1];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= N - i; ++j) {
            if (i == 0 ) {
                dp[j][j + i] = V[j] - V[j - 1];
            }
            else {
                dp[j][j + i] = V[j + i] - V[j - 1] - min(dp[j + 1][j + i], dp[j][j + i - 1]);
            }
        }
    }
    cout << dp[1][N] << "\n";
}
