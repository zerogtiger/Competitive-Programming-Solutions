#include "iostream"
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7, inf = 0x3f3f3f3f, MM = 2e5 + 5;
bool visited[MM];
ll cnt[MM];
vector<int> adj[MM];
ll dp[MM];
int in[MM], out[MM];
int t = 0;
vector<int> order;

void dfs(int curr) {
    in[curr] = t++;
    for (auto &i : adj[curr]) {
        if (in[i] == inf) {
            dfs(i);
        }
    }
    order.push_back(curr);
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(in, inf, sizeof(in));
    for (int i = 1; i <= N; ++i) {
        if (in[i] == inf) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    dp[1] = 1;
    for (auto &i : order) {
        for (auto &j : adj[i]) {
            dp[j] = (dp[i] + dp[j])%mod;
            visited[j] = true;
        }
    }
    cout << dp[N];
    
}
