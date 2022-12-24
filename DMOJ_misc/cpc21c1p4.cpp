// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 3e5 + 5;

int N, M;
vector<int> adj[MM];
int vis[MM];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    memset(vis, -1, sizeof(vis));
    for (int i = N; i >= 1; i--)
    {
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (vis[curr] != -1) continue;
            vis[curr] = i;
            for (auto n : adj[curr])
            {
                if (vis[n] == -1)
                {
                    q.push(n);
                }
            }
        }
    }
    for (int i = N; i >= 1; i--) 
    {
        if (vis[i] != -1 && vis[i] != i)
        {
            cout << i << " " << vis[i] << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";

}