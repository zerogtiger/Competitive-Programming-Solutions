// Dijkstra variant

#include "iostream"
#include "vector"
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
const int MM = 1e5 + 5, mod = 1e9+7;
vector<pair<int, ll>> adj[MM];
ll dist[MM], cnt[MM], mncnt[MM], mxcnt[MM];
bool visited[MM];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<ll, int>> pq;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    pq.push({0, 1});
    dist[1] = 0;
    cnt[1] = 1;
    mncnt[1] = 0;
    mxcnt[1] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (visited[curr.second]) {
            continue;
        }
        visited[curr.second] = true;
        for (auto &p : adj[curr.second]) {
            if (dist[p.first] > dist[curr.second] + p.second) {
                dist[p.first] = dist[curr.second] + p.second;
                cnt[p.first] = cnt[curr.second];
                mncnt[p.first] = mncnt[curr.second] + 1;
                mxcnt[p.first] = mxcnt[curr.second] + 1;
                pq.push({-dist[p.first], p.first});
            }
            else if (dist[p.first] == dist[curr.second] + p.second) {
                cnt[p.first] = (cnt[p.first] +  cnt[curr.second])%mod;
                mncnt[p.first] = min(mncnt[p.first], mncnt[curr.second] + 1);
                mxcnt[p.first] = max(mxcnt[p.first], mxcnt[curr.second] + 1);
            }
        }
    }
    cout << dist[N] << " " << cnt[N] << " " << mncnt[N] << " " << mxcnt[N] << "\n";
}
