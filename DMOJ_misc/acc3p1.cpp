// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e6 + 5;

int K, N, a[MM], m[MM];
ll ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for (int l = 1, r = 1; r <= N; r++)
    {
        if (m[a[r]] == 0) cnt ++;
        m[a[r]] = m[a[r]] + 1;
        while (cnt >= K)
        {
            ans += (N - r + 1);
            if (m[a[l]] == 1) cnt--;
            m[a[l]] = m[a[l]]-1;
            l++;
        }
    }
    cout << ans << endl;
}