// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5, mod = 13371337;

int n, t, adj[15][15], dp[15][1<<15];

int fun(int p, int mask)
{
    if (p == n-1) return 1;
    if (dp[p][mask] >= 0) return dp[p][mask];
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (((1<<i)&mask) == 0 && adj[p][i])
        {
            ret = (ret + fun(i, (1<<i)|mask))%mod;
        }
    }
    return dp[p][mask] = ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for (; t>0; t--)
    {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> adj[i][j];
            }
        }
        cout << fun(0,1) << "\n";
    }
}