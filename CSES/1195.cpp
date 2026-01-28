#include "iostream"
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

const int MM = 1e5 + 4;
vector<pair<int, int>> adj[MM], jda[MM];
bool vis[MM];
bool siv[MM];
ll dist[MM];
ll tsid[MM];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        jda[b].push_back({a, c});
    }
    priority_queue<pair<ll, int>> pq; // -dist, node
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(tsid, 0x3f3f3f3f, sizeof(tsid));

    // forwarded
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (vis[curr.second]) {
            continue;
        }
        vis[curr.second] = true;
        for (auto &p : adj[curr.second]) {
            if (dist[p.first] > dist[curr.second] + p.second) {
                dist[p.first] = dist[curr.second] + p.second;
                pq.push({-dist[p.first], p.first});
            }
        }
    }

    // backward
    pq.push({0, N});
    tsid[N] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (siv[curr.second]) {
            continue;
        }
        siv[curr.second] = true;
        for (auto &p : jda[curr.second]) {
            if (tsid[p.first] > tsid[curr.second] + p.second) {
                tsid[p.first] = tsid[curr.second] + p.second;
                pq.push({-tsid[p.first], p.first});
            }
        }
    }

    ll ans = 1e18;
    for (int i = 1; i <= N; ++i) {
        for (auto p : adj[i]) {
            ans = min(ans, dist[i] + tsid[p.first] + p.second/2);
        }
    }
    cout << ans << "\n";
}
