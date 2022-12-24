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

int N, D, a[MM], dp[MM]; deque<pi> dq;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> D;
    for (int i = 1; i <= N; i++) 
    {
        int temp; cin >> temp;
        if (i == 1) {
            dp[i] = temp;
            dq.push_back({dp[i], i});
        }
        else 
        {
            while (!dq.empty() && dq.front().second < i-D) {
                dq.pop_front();
            }
            dp[i] = dq.front().first+temp;
            while (!dq.empty() && dq.back().first > dp[i])
            {
                dq.pop_back();
            }
            dq.push_back({dp[i], i});
        }
    }
    cout << dp[N];
}