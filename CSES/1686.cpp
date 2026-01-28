#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;
const int MM = 1e5 + 4;
ll value[MM];
bool visited[MM];
vector<int> adj[MM], jda[MM];
vector<int> order, topo_order;
vector<int> topo_adj[MM];
map<int, ll> topo_val;
int lead[MM];

void dfs(int curr)
{
    visited[curr] = true;
    for (auto& i : adj[curr])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    order.push_back(curr);
}

ll topo(int curr, int led, ll accum)
{
    visited[curr] = true;
    lead[curr] = led;
    accum += value[curr];
    for (auto& i : jda[curr])
    {
        if (visited[i] && lead[i] != led)
        {
            topo_adj[lead[i]].push_back(led);
        }
        if (!visited[i])
        {
            accum = topo(i, led, accum);
        }
    }
    return accum;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> value[i];
    }
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(visited, 0, sizeof(visited));
    map<int, ll> dp;
    ll ans = 0;
    for (auto &i : order) {
        if (!visited[i]) {
            topo_val[i] = topo(i, i, 0);
            dp[i] = topo_val[i];
            ans = max(ans, dp[i]);
        }
        topo_order.push_back(i);
    }
    for (auto &i : topo_order) {
        for (auto &j : topo_adj[i]) {
            dp[j] = max(dp[j], dp[i] + topo_val[j]);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << "\n";
}
