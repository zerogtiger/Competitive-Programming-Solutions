#include "iostream"
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MM = 1e5 + 4, inf = 0x3f3f3f3f;
int in[MM], out[MM];
vector<int> adj[MM];
int t = 0;
vector<int> order;

bool dfs(int curr)
{
    for (auto& i : adj[curr]) {
        if (in[curr] >= in[i] && out[i] >= inf) {
            cout << "IMPOSSIBLE\n";
            return true;
        }
        else if (in[i] == inf) {
            in[i] = t++;
            if (dfs(i)) {
                return true;
            }
        }
    }
    out[curr] = t++;
    order.push_back(curr);
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(in, inf, sizeof(in));
    memset(out, inf, sizeof(out));
    for (int i = 1; i <= N; ++i) {
        if (in[i] >= inf) {
            in[i] = t++;
            if (dfs(i)) {
                return 0;
            }
        }
    }
    reverse(order.begin(), order.end());
    for (auto& i : order) {
        cout << i << " ";
    }
}
