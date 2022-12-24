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

int n, s;
ll a[MM];
int ans[MM];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int lft = 1, rit = 0;
    for (int i = 1; i <= n; i++)
    {
        while (lft < i && a[i-1] - a[lft - 1] > s)
            lft++;
        while (rit < n && a[rit+1] - a[i-1] <= s)
            rit++;
        int mini = min(i - lft, rit - i+1);
        ans[i-mini] = max(ans[i-mini], mini);
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = max(ans[i - 1] - 1, ans[i]);
        cout << ans[i] * 2 << endl;
    }
}
