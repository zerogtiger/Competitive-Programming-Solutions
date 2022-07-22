//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 3e5 + 5;

int n, a[MM];
stack<pi> mini, maxi;
pi minip[MM], maxip[MM];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    mini.push({-1, 0});
    maxi.push({0x3f3f3f3f, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (mini.top().first >= a[i])
        {
            minip[mini.top().second].second = i - 1;
            mini.pop();
        }
        minip[i].first = mini.top().second + 1;
        mini.push({a[i], i});
        while (maxi.top().first <= a[i])
        {
            maxip[maxi.top().second].second = i - 1;
            maxi.pop();
        }
        maxip[i].first = maxi.top().second + 1;
        maxi.push({a[i], i});
    }
    while (mini.top().first != -1)
    {
        minip[mini.top().second].second = n;
        mini.pop();
    }
    while (maxi.top().first != 0x3f3f3f3f)
    {
        maxip[maxi.top().second].second = n;
        maxi.pop();
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i - minip[i].first;
        int r = minip[i].second - i;
        ll minv = (l + r + (ll)l * r) * a[i];

        l = i - maxip[i].first;
        r = maxip[i].second - i;
        ll maxv = (l + r + (ll)l * r) * a[i];
        ans += maxv - minv;
    }
    cout << ans << endl;
}
