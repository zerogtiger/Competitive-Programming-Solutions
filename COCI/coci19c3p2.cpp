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

int n, q, p[MM];
string s;
pi a[MM];

bool check(int mid)
{
    int c[26][n + 2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            c[j][i] = c[j][i - 1];
        }
        if (p[i] > mid)
            c[s[i - 1] - 'a'][i]++;
    }
    for (int i = 1; i <= q; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (c[j][a[i].second] - c[j][a[i].first - 1] >= 2)
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s);
    n = s.length();
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        p[temp] = i;
    }
    int l = 0, r = n, ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}