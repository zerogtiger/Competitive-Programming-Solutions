#include "iostream"
#include "vector"
#include <algorithm>
#include <queue>
using namespace std;

const int MM = 1e5 + 3;
int par[MM];
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> adj[N + 1];
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    par[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto& i : adj[curr]) {
            if (par[i] == 0) {
                par[i] = curr;
                q.push(i);
                if (i == N) {
                    goto end;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
end:
    vector<int> path;
    int curr = N;
    while (curr != 1) {
        path.push_back(curr);
        curr = par[curr];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (auto& i : path) {
        cout << i << " ";
    }
}
