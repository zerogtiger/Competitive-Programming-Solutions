#include "iostream"
#include "vector"
#include <cstring>
using namespace std;

typedef long long ll;
const int MM = 22;
const ll mod = 1e9 + 7;
vector<int> adj[MM];
ll dp[1 << 20][MM];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    dp[1][0] = 1;
    for (int mask = 1; mask < 1 << N; ++mask) {
        if (!(mask & 1)) {
            continue;
        }
        for (int i = 0; i < N; ++i) {
            if ((mask  & (1 << i))) {
                for (auto &j : adj[i]) {
                    if (!(mask & (1 << j))) {
                        dp[mask | (1 << j)][j] = (dp[mask | (1 << j)][j] + dp[mask][i])%mod;
                    }
                }
            }
        }
    }
    cout << dp[(1 << N) - 1][N - 1];
}
