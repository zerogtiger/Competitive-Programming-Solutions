#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
using namespace std;

const int MM = 1e5 + 5, inf = 0x3f3f3f3f;
vector<int> adj[MM];
int out[MM], in[MM];
vector<int> topo;
int dp[MM];
int par[MM];

int t = 0;

bool dfs(int curr)
{
    in[curr] = t++;
    for (auto& i : adj[curr]) {
        if (in[curr] >= in[i] && out[curr] != inf) {
            cout << "IMPOSSIBLE";
            return true;
        }
        else if (in[i] == inf) {
            if (dfs(i)) {
                return true;
            }
        }
    }
    topo.push_back(curr);
    out[curr] = t++;
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(in, inf, sizeof(in));
    memset(out, inf, sizeof(out));
    for (int i = 1; i <= N; ++i) {
        if (in[i] == inf) {
            if (dfs(i)) {
                return 0;
            }
        }
    }
    reverse(topo.begin(), topo.end());
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[1] = 1;
    for (int j = 1; j < N; ++j) {
        int i = topo[j - 1];
        for (auto& a : adj[i]) {
            if (dp[a] < dp[i] + 1) {
                par[a] = i;
            }
            dp[a] = max(dp[a], dp[i] + 1);
        }
    }
    if (dp[N] < 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dp[N] << "\n";
    int curr = N;
    vector<int> tmp;
    while (curr != 1) {
        tmp.push_back(curr);
        curr = par[curr];
    }
    cout << 1;
    reverse(tmp.begin(), tmp.end());
    for (auto& i : tmp)
        cout << " " << i;
}
