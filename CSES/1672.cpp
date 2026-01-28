// Floyd-Warshall

#include "iostream"
#include "vector"
#include <cstring>
using namespace std;

typedef long long ll;
const int MM = 503;

ll dist[MM][MM];
vector<pair<int, ll>> adj[MM];
int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 0; i < M; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << (dist[a][b] >= 0x3f3f3f3f3f3f3f3f ? -1 : dist[a][b]) << "\n";
    }
}
