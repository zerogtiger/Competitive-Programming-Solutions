// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 8388620;

ll N, K, a[MM], dp[MM]; deque<ll> dq;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    dp[0] = 0;
    dq.push_back(0);
    for (int i = 1; i <= N+1; i++) 
    {
        if (i != N+1) cin >> a[i];
        while (!dq.empty() && dq.front() < i-K) dq.pop_front();
        dp[i] = dp[dq.front()]+a[i];
        while (!dq.empty() && dp[dq.back()]>dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[N+1] << "\n";
    stack<int> s; int curr = N+1;
    for (int i = N; i >= 1; i--) 
    {
        if (dp[i] == dp[curr]-a[curr]) 
        {
            s.push(i);
            curr=i;
        }
    }
    bool first = true;
    while (!s.empty()) {
        cout << (first? "" : " ") << s.top();
        first = false;
        s.pop();
    }
    cout << "\n";
}