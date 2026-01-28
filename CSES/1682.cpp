#include "iostream"
#include "set"
#include "vector"
#include <algorithm>
#include <cstring>
#include <queue>
#include <variant>
using namespace std;

const int MM = 1e5 + 5;
vector<int> adj[MM], jda[MM];
bool visited[MM];

// weird syntax wth
void dfs(vector<int> (&adj)[MM], int curr)
{
    visited[curr] = true;
    for (auto& i : adj[curr])
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(adj, i);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }
    dfs(adj, 1);
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            cout << "NO\n" << 1 << " " << i << "\n";
            return 0;
        }
    }
    memset(visited, 0, sizeof(visited));
    dfs(jda, 1);
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            cout << "NO\n" << i << " " << 1 << "\n";
            return 0;
        }
    }
    cout << "YES\n";
}

// SCC code which was useless oops
//
// const int MM = 1e5 + 5;
// vector<int> adj[MM], jda[MM];
// vector<int> component_adj[MM];
// bool visited[MM];
// vector<int> order;
// int component_dsu[MM];
// vector<int> component_order;
//
// void dfs(int curr)
// {
//     visited[curr] = true;
//     for (auto& i : adj[curr])
//     {
//         if (!visited[i])
//         {
//             dfs(i);
//         }
//     }
//     order.push_back(curr);
// }
//
// void make_component(int curr, int lead)
// {
//     component_dsu[curr] = lead;
//     for (auto& i : jda[curr])
//     {
//         if (visited[i] && component_dsu[i] != lead)
//         {
//             component_adj[component_dsu[i]].push_back(lead);
//         }
//         else if (!visited[i])
//         {
//             make_component(i, lead);
//         }
//     }
// }
//
// int main()
// {
//     int N, M;
//     cin >> N >> M;
//     for (int i = 1; i <= M; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         jda[b].push_back(a);
//     }
//     for (int i = 1; i <= N; ++i)
//     {
//         if (!visited[i])
//             dfs(i);
//     }
//     reverse(order.begin(), order.end());
//     memset(visited, 0, sizeof(visited));
//     for (auto& i : order)
//     {
//         if (!visited[i])
//         {
//             make_component(i, i);
//             component_order.push_back(i);
//         }
//     }
//     queue<int> q;
//     q.push(1);
//     set<int> visited_components;
//     visited_components.insert(1);
//     while (!q.empty()) {
//         int curr = q.front();
//         q.pop();
//         for (auto &c : component_adj[curr]) {
//             if (!visited_components.count(c)) {
//                 visited_components.insert(c);
//                 q.push(c);
//             }
//         }
//     }
//     for (int i = 1; i <= N; ++i) {
//         if (!visited_components.count(component_dsu[i])) {
//             cout << "NO\n" << 1 << " " << i << "\n";
//             return 0;
//         }
//     }
//     cout << "YES\n";
//
// }
