//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5 + 6;

int t, n;
ll a[MM], b[MM], c[MM];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        ll l, r, a0, b0, c0;
        cin >> l >> r >> a0 >> b0 >> c0;
        a[l + 1] += a0;
        a[l + 2] += a0;
        a[r + 1] -= a0 * (r - l + 1) * (r - l + 1);
        a[r + 2] += a0 * (r - l + 1) * (r - l + 1) + a0 * (r - l) * (r - l) - 2 * a0;
        a[r + 3] -= a0 * (r - l) * (r - l);

        b[l + 1] += b0;
        b[r + 1] -= b0 * (r - l + 1);
        b[r + 2] += b0 * (r - l);

        c[l] += c0;
        c[r + 1] -= c0;
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            a[j] += a[j - 1];
            if (i < 3)
                b[j] += b[j - 1];
            if (i < 2)
                c[j] += c[j - 1];
        }
    }
    for (int i = 1; i <= t; i++)
    {
        cout << a[i] + b[i] + c[i] << " ";
    }
    cout << endl;
}
