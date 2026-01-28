#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int MM = 2e5 + 5;
vector<int> adj[MM], jda[MM];

inline int neg(int curr) { return 2 * curr + 1; }
inline int pos(int curr) { return 2 * curr; }
inline int flip(int curr) { return (curr % 2 == 1 ? curr - 1 : curr + 1); }

vector<int> order;
int lead[MM];
bool visited[MM];
int comp[MM];
vector<int> topo_order;

void dfs(int curr)
{
    visited[curr] = true;
    for (auto& i : adj[curr])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    order.push_back(curr);
}

bool topo(int curr, int led, set<int>& st)
{
    visited[curr] = true;
    lead[curr] = led;
    if (st.count(flip(curr)))
    {
        cout << "IMPOSSIBLE\n";
        return true;
    }
    st.insert(curr);
    for (auto& i : jda[curr])
    {
        if (visited[i]) {
            continue;
        }
        if (topo(i, led, st))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        char a, b;
        int A, B;
        cin >> a >> A >> b >> B;
        A = (a == '-' ? neg(A) : pos(A));
        B = (b == '-' ? neg(B) : pos(B));
        adj[flip(A)].push_back(B);
        adj[flip(B)].push_back(A);
        jda[B].push_back(flip(A));
        jda[A].push_back(flip(B));
    }
    for (int i = pos(1); i <= neg(M); ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(visited, 0, sizeof(visited));
    for (auto& i : order)
    {
        if (!visited[i])
        {
            set<int> st;
            if (topo(i, i, st))
                return 0;
            topo_order.push_back(i);
        }
    }
    map<int, int> lead_to_comp;
    for (int i = 0; i < topo_order.size() ; ++i) {
        lead_to_comp[topo_order[i]] = i;
    }
    for (int i = 1; i <= M; ++i) {
        if (lead_to_comp[lead[pos(i)]] > lead_to_comp[lead[neg(i)]]) {
            cout << "+ ";
        }
        else {
            cout << "- ";
        }
    }
}
