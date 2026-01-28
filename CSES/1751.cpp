#include "iostream"
#include "vector"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <tuple>
using namespace std;

const int MM = 2e5 + 4, inf = 0x3f3f3f3f;
int tel[MM], indeg[MM];
int cycle_lead[MM];
int depth[MM];
int leader[MM];
int ancester[MM][32];
int in[MM], out[MM];
int t = 0;
map<int, int> loop_size;
vector<int> order;

void topo(int curr)
{
    in[curr] = t++;
    if (in[tel[curr]] == inf)
    {
        topo(tel[curr]);
    }
    out[curr] = t++;
    order.push_back(curr);
}

tuple<int, int, int> dfs(int curr, int lead, int curr_depth)
{ // depth, cycle lead, cycle ending node
    in[curr] = t++;
    leader[curr] = lead;
    depth[curr] = curr_depth;
    if (in[curr] >= in[tel[curr]] && out[tel[curr]] == inf)
    {
        cycle_lead[curr] = curr;
        depth[curr] = curr_depth;
        leader[curr] = 0;
        out[curr] = t++;
        loop_size[curr] = (curr == tel[curr] ? 1 : depth[curr] - depth[tel[curr]] + 1); // BUG
        return make_tuple(curr_depth, curr, tel[curr] == curr ? -1 : tel[curr]);
    }
    else if (in[tel[curr]] != inf && out[tel[curr]] != inf)
    {
        cycle_lead[curr] = (leader[tel[curr]] == 0 ? tel[curr] : cycle_lead[tel[curr]]);
        depth[curr] = depth[tel[curr]] - 1;
        out[curr] = t++;
        return make_tuple(depth[curr], cycle_lead[curr], -1);
    }
    auto ret = dfs(tel[curr], lead, curr_depth + 1);
    cycle_lead[curr] = get<1>(ret);
    depth[curr] = get<0>(ret) - 1;
    if (get<2>(ret) > 0)
    {
        leader[curr] = 0;
    }
    out[curr] = t++;
    return make_tuple(get<0>(ret) - 1, get<2>(ret) == curr ? curr : get<1>(ret),
                      get<2>(ret) == curr ? -1 : get<2>(ret));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N;
    memset(ancester, -1, sizeof(ancester));
    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        ancester[i][0] = a;
        tel[i] = a;
        indeg[a]++;
    }
    for (int pw = 1; pw <= 30; ++pw)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (ancester[i][pw - 1] == -1)
            {
                continue;
            }
            ancester[i][pw] = ancester[ancester[i][pw - 1]][pw - 1];
        }
    }
    memset(in, 0x3f3f3f3f, sizeof(in));
    memset(out, 0x3f3f3f3f, sizeof(out));
    for (int i = 1; i <= N; ++i)
    {
        if (in[i] == inf)
        {
            topo(i);
        }
    }
    reverse(order.begin(), order.end());
    t = 0;
    memset(in, 0x3f3f3f3f, sizeof(in));
    memset(out, 0x3f3f3f3f, sizeof(out));
    for (auto& i : order)
    {
        if (in[i] == inf)
        {
            dfs(i, i, 0);
        }
    }

    // for (auto& i : order)
    //     cout << i << " ";
    // cout << "\n";
    // for (int i = 1; i <= N; ++i)
    // {
    //     cout << cycle_lead[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= N; ++i)
    // {
    //     cout << depth[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= N; ++i)
    // {
    //     cout << leader[i] << " ";
    // }
    // cout << "\n";
    // for (auto& p : loop_size)
    // {
    //     cout << p.first << ": " << p.second << "\n";
    // }

    for (int i = 1; i <= N; ++i)
    {
        if (!leader[i])
        {
            cout << loop_size[cycle_lead[i]] << " ";
        }
        else
        {
            cout << depth[cycle_lead[i]] - depth[i] + loop_size[cycle_lead[cycle_lead[i]]] << " ";
        }
    }
}

/*
13 1
2 3 7 3 4 5 8 9 3 8 10 10 9
   */
