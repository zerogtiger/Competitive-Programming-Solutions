//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e4 + 2;

int n, m;
char g[MM][MM];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1, x, y, w, h; i <= m; i++)
    {
        cin >> x >> y >> w >> h;
        g[x + 1][y + 1]++;
        g[x + w + 1][y + 1 + h]++;
        g[x + 1][y + 1 + h]--;
        g[x + 1 + w][y + 1]--;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] += (g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1]);
            ans += (g[i][j] & 1);
        }
    }
    cout << ans << endl;
}
