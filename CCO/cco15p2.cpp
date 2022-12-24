// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5;

int n, m, adj[18][18], dp[18][1<<18];

int fun(int curr, int mask)
{
    if (curr == n-1) return 0;
    if (dp[curr][mask] >= 0) return dp[curr][mask];
    int maxi = -0x3f3f3f3f;
    for (int i = 0; i < n; i++) 
    {
        if (((1<<i) & mask) == 0 && adj[curr][i] > 0)
        {
            maxi = max(maxi, adj[curr][i] + fun(i, (1<<i)|mask));
        }
    }
    return dp[curr][mask] = maxi;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 1, s, d, l; i <= m; i++) 
    {
        cin >> s >> d >> l;
        adj[s][d] = l;
    }
    cout << fun(0, 1) << endl;
}