// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;
const int MM = 5e3 + 5, add = 2e6;
typedef long long ll;

int a[MM], n, q;
ll g[MM][MM], freq[(int)4e6 + 3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int l = 1; l <= n; l++)
    {
        for (int r = l + 1; r <= n; r++)
        {
            g[l][r] = freq[-a[l] - a[r] + add];
            freq[a[r] + add]++;
        }
        for (int r = l + 1; r <= n; r++)
        {
            freq[a[r] + add]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
        cout << endl;
    }
    for (int i = 1, l, r; i <= q; i++)
    {
        cin >> l >> r;
        cout << g[r][r] - g[r][l - 1] - g[l - 1][r] + g[l - 1][l - 1] << "\n";
    }
}
