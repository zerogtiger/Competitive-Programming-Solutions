// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5, mod = 1e9+7;

int n, c[21][21], dp[1<<21];

int fun(int p, int mask)
{
    if (p == n) return 1;
    if (dp[mask] >= 0) return dp[mask];
    int num = 0;
    for (int i = 0; i < n; i++) 
    {
        if (((1 << i) & mask) == 0 && c[p][i])
        {
            num = (num + fun(p+1, ((1<<i)|mask)))%mod;
        }
    }
    return dp[mask] = num;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> c[i][j];
        }
    }
    cout << fun(0, 0)%mod << endl;
}