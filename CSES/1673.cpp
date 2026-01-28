#include "iostream"
#include "vector"
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int MM = 2506;
ll dist[MM];
bool visited[MM];

vector<pair<ll, ll>> adj[MM];
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, -c});
    }
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    for (int cnt = 0; cnt < N; ++cnt) {
        bool changed = false;
        bool changedN = false;
        for (int i = 1; i <= N; ++i) {
            auto& v = adj[i];
            for (auto& p : v) {
                if (dist[i] < 0x3f3f3f3f3f3f3f3f && dist[p.first] > dist[i] + p.second) {
                    if (cnt == N - 1) {
                        q.push(p.first);
                        visited[p.first] = true;
                        changed = true;
                    }
                    dist[p.first] = dist[i] + p.second;
                }
            }
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto& i : adj[curr]) {
            if (!visited[i.first]) {
                q.push(i.first);
                visited[i.first] = true;
            }
        }
    }
    cout << (dist[N] >= 0x3f3f3f3f3f3f3f3f || visited[N] ? -1 : -dist[N]) << "\n";
}
