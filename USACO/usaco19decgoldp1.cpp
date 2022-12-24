// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1003;

priority_queue<pii, vector<pii>, greater<pii>> q;
int n, m, dis[MM][MM], ans; bool vis[MM][MM]; vector<pii> adj[MM];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v, c, f; i <= m; i++)
    {
        cin >> u >> v >> c >> f;
        adj[u].push_back({c, {v, f}}); adj[v].push_back({c, {u, f}});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][1000] = 0; q.push({0, {1, 1000}});
    while (!q.empty())
    {
        auto cur = q.top(); q.pop();
        int d = cur.first, u = cur.second.first, f=cur.second.second;
        if (vis[u][f]) continue;
        vis[u][f] = true;
        if (u==n) ans = max(ans, f*(int)1e6 / d);
        for (auto e : adj[u]) {
            int w= e.first, v= e.second.first, f2 = min(f, e.second.second);    
            if (dis[v][f2] > dis[u][f]+w) 
            {
                dis[v][f2] = dis[u][f]+w; q.push({dis[v][f2], {v, f2}});
            }
        }
    }
    cout << ans << "\n";
}