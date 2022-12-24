// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 2e5+5;

int N, K; ll a[MM]; deque<ll> dq; ll ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) 
    {
        cin >> a[i];
        a[i+N] = a[i];
    }
    for (int i = 1; i <= 2*N; i++) 
    {
        a[i]+= a[i-1];
        if (i>=K)
        {
            while (!dq.empty() && dq.front() < i-K)
            {
                dq.pop_front();
            }
            ans = max(ans, a[i]-a[dq.front()]);
        }
        while (!dq.empty() && a[dq.back()] > a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << ans << "\n";

}