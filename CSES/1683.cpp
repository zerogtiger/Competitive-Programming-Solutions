#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MM = 1e5 + 5;
vector<int> adj[MM], jda[MM];
bool visited[MM];
vector<int> order;
int component_dsu[MM];
vector<int> component_order;

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

void make_component(int curr, int lead)
{
    visited[curr] = true;
    component_dsu[curr] = lead;
    for (auto& i : jda[curr])
    {
        if (!visited[i])
        {
            make_component(i, lead);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
    memset(visited, 0, sizeof(visited));
    for (auto& i : order)
    {
        if (!visited[i])
        {
            make_component(i, i);
            component_order.push_back(i);
        }
    }
    cout << component_order.size() << "\n";
    map<int, int> mp;
    for (int i = 1; i <= N; ++i) {
        if (!mp.count(component_dsu[i])) {
            mp[component_dsu[i]] = mp.size() + 1;
        }
        cout << mp[component_dsu[i]] << " ";
    }
}

