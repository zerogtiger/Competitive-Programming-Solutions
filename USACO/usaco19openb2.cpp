#include "iostream"
#include "vector"
using namespace std;
int main()
{
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans = -1;
    for (int i = 1; i <= N; ++i) {
        if (adj[i].size() == 0 && ans < 0) {
            ans = i;
        }
        else if (adj[i].size() == 0) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << "\n";
}
