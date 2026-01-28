#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
using namespace std;

const int MM = 1e5 + 5, inf = 0x3f3f3f3f;
vector<int> adj[MM];
int in[MM];
int out[MM];
int par[MM];

static int t = 0;

bool dfs(int curr, int currdist)
{
    bool ret = false;
    for (auto& i : adj[curr]) {
        if (currdist - in[i] >= 1 && out[i] >= inf) {
            vector<int> tmp;
            tmp.push_back(i);
            while (curr != i) {
                tmp.push_back(curr);
                curr = par[curr];
            }
            reverse(tmp.begin(), tmp.end());
            cout << tmp.size() + 1 << "\n";
            cout << curr << " ";
            for (auto& i : tmp) {
                cout << i << " ";
            }
            return true;
        }
        else if (in[i] == inf) {
            in[i] = t++;
            par[i] = curr;
            ret = ret || dfs(i, in[i]);
            if (ret) {
                return true;
            }
        }
    }
    out[curr] = t++;
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
        if (in[i] == inf) {
            in[i] = t++;
            if (dfs(i, in[i]))
                return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
