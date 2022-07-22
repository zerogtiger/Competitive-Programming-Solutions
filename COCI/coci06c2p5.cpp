//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5 + 5;

int R, c, a[405][405];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> c;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char temp;
            cin >> temp;
            a[i][j] = (temp == 'X');
            a[i][j] += a[i][j - 1];
        }
    }
    int maxi = 0;
    for (int l = 1; l <= c; l++)
    {
        for (int r = l; r <= c; r++)
        {
            int curr = 0;
            for (int i = 1; i <= R + 1; i++)
            {
                if (a[i][r] - a[i][l - 1] != 0 || i == R + 1)
                {
                    maxi = max(maxi, (i - curr - 1 > 0 ? (2 * (r - l + 1 + i - curr - 1)) : 0));
                    curr = i;
                }
            }
        }
    }
    cout << maxi - 1 << endl;
}
