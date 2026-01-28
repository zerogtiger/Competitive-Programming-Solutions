#include "iostream"
#include <queue>
#include <vector>
using namespace std;

const int MM = 1e5 + 4;
int dsu[MM];
int find(int i) {
    if (dsu[i] == i) {
        return i;
    }
    return dsu[i] = find(dsu[i]);
}

int ans[MM];
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        dsu[i] = i;
    }
    vector<int> adj[N + 1];
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i =1; i <= N; ++i) {
        if (!ans[i]) {
            // BFS
            queue<int> q;
            ans[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto  &n : adj[curr]) {
                    if (ans[n] == 0) {
                        ans[n] = 3 - ans[curr];
                        q.push(n);
                    }
                    else if (ans[curr] == ans[n]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << " ";
    }
}
