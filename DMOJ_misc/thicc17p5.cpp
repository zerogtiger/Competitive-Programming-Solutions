// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e6+5;

int N, K, a[MM], m[MM], cnt; ll ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    for (int r = 1, l = 1; r <= N; r++) 
    {
        cin >> a[r];
        if (m[a[r]] == 0) cnt ++;
        m[a[r]]++;
        while (cnt >= K) 
        {
            ans += (N-r+1);
            if (m[a[l]] == 1) cnt--;
            m[a[l]]--;
            l++;
        }
    }
    cout << ans << endl;
}