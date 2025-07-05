#include "iostream"
#include "vector"
using namespace std;

int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans(N + 1);
    for (int i = 1; i <= N; ++i) {
        bool used[] = {false, false, false, false, false};
        for (auto& a : adj[i])
            used[ans[a]] = true;
        for (int j = 1; j <= 4; ++j) {
            if (!used[j]) {
                ans[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= N; ++i) { 
        cout << ans[i];
    }
    cout << "\n";
}
