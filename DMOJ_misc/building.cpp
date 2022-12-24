// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5;

ll N, D, X, Y, a[MM], t[MM]; ll dp[MM]; stack<int> s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> D >> X >> Y;
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= N; i++) 
    {
        cin >> a[i];
        while (!s.empty() && a[s.top()]<a[i]) {
            if (i-s.top() <= D) t[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    fill_n(dp, MM, 1e18);
    dp[1] = 0;
    for (int i = 1; i <= N; i++) 
    {
        dp[i+1] = min(dp[i+1], dp[i]+Y);
        dp[i+2] = min(dp[i+2], dp[i]+Y);
        dp[t[i]] = min(dp[t[i]], dp[i]+X);
    }
    cout << dp[N] << "\n";
}