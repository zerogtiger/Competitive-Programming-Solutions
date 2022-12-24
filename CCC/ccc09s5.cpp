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
int m, n, k, g[30005][1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 1, b, r, x, y; i <= k; i++)
    {
        cin >> x >> y >> r >> b;
        for (int a = max(1, y - r); a <= min(m, y + r); a++)
        {
            int p1 = sqrt(r * r - (a - y) * (a - y)) + x;
            int p2 = ceil(-sqrt(r * r - (a - y) * (a - y))) + x;
            g[a][min(n+1, p1+1)]-=b;
            g[a][max(1, p2)]+=b;
        }
    }
    ll maxi = 0, count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] += g[i][j - 1];
            if (g[i][j] > maxi)
            {
                maxi = g[i][j];
                count = 0;
            }
            count += g[i][j] == maxi;
        }
    }

    cout << maxi << "\n"
         << count << endl;
}
