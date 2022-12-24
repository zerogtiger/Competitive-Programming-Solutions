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

int w, h, n, a[253][253];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> n;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int maxi = 0;
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            for (int k = i+1; k <= h; k++)
            {
                int l = min(n/(k-i)+j, w);
                if (maxi < a[k][l] - a[k][j] - a[i][l] + a[i][j])
                {
                    maxi = max(a[k][l] - a[k][j] - a[i][l] + a[i][j], maxi);
                    // cout << k << " " << l << " " << i << " " << j << endl;
                }
            }
        }
    }
    cout << maxi << endl;
}
