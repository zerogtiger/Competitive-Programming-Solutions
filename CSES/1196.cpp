// NO WORK
#include "iostream"
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

const int MM = 1e5 + 5;
vector<pair<int, ll>> adj[MM], jda[MM];
ll dist[MM], tsid[MM];
bool vis[MM], siv[MM];
int par[MM], rap[MM];
int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        jda[b].push_back({a, c});
    }
    priority_queue<pair<ll, int>> pq;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(tsid, 0x3f3f3f3f, sizeof(tsid));
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (vis[curr.second])
            continue;
        vis[curr.second] = true;
        for (auto &p : adj[curr.second]) {
            if (dist[p.first] > dist[curr.second] - curr.first) {
                dist[p.first] = dist[curr.second] - curr.first;
                pq.push({-dist[p.first], p.first});
                par[p.first] = curr.second;
            }
        }
    }

    pq.push({0, N});
    tsid[N] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (siv[curr.second])
            continue;
        siv[curr.second] = true;
        for (auto &p : jda[curr.second]) {
            if (tsid[p.first] > tsid[curr.second] - curr.first) {
                tsid[p.first] = tsid[curr.second] - curr.first;
                pq.push({-tsid[p.first], p.first});
                rap[p.first] = curr.second;
            }
        }
    }
    int curr = N;
}
