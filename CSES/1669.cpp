#include "iostream"
#include "vector"
#include <cstring>
using namespace std;

const int MM = 1e5 + 5, inf = 0x3f3f3f3f;
vector<int> adj[MM];
int dist[MM];
int par[MM];
bool dfs(int curr, int currdist) {
    bool ret = false;
    for (auto &i : adj[curr]) {
        if (currdist - dist[i] >= 2) {
            int length = currdist - dist[i] + 1;
            cout << length  + 1<< "\n";
            cout << i << " ";
            while (length--) {
                cout << curr << " ";
                curr = par[curr];
            }
            return true;
        }
        else if (dist[i] == inf) {
            dist[i] = currdist + 1;
            par[i] = curr;
            ret = ret || dfs(i, currdist + 1);
            if (ret) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i =0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    memset(dist, inf, sizeof(dist));
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == inf) {
            // dfs
            dist[i] = 0;
            if (dfs(i, 0)) 
                return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
