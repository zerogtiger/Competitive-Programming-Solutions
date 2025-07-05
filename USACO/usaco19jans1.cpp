#include "iostream"
#include "vector"
using namespace std;
int main() {

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    int mx = 0;
    for (int i =0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mx = max(mx, (int) adj[a].size());
        mx = max(mx, (int) adj[b].size());
    }
    cout << mx + 1 << "\n";
}
