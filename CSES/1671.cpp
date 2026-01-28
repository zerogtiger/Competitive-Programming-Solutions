// Dijkstra
#include "iostream"
#include "vector"
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
const int MM = 1e5 + 3;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[MM];
ll dist[MM];
bool visited[MM];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<ll, int>> pq; // distance, node name
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (visited[p.second]) {
            continue;
        }
        visited[p.second] = true;
        for (auto& i : adj[p.second]) {
            if (dist[i.first] > -p.first + i.second) {
                pq.push({p.first - i.second, i.first});
                dist[i.first] = -p.first + i.second;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << dist[i] << " ";
    }
}
