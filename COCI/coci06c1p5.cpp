// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5 + 5;

int n;
double a[20][20], dp[1 << 20];

double fun(int m, int mask)
{
    if (m == n)
    {
        return 1;
    }
    if (dp[mask] >= 0)
    {
        return dp[mask];
    }
    double maxi = -1;
    for (int i = 0; i < n; i++)
    {
        if (((1 << i) & mask) == 0)
        {
            maxi = max(maxi, a[i][m] * fun(m + 1, ((1 << i) | mask)));
        }
    }
    return dp[mask] = maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, in; j < n; j++)
        {
            cin >> in;
            a[i][j] = in / 100.0;
        }
    }
    printf("%.9f\n", fun(0,0)*100);
}